#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double R;//double long double の切り替え cmathの関数はオーバーロードに対応しているので問題ない
typedef complex<R> Point;
typedef pair<Point , Point> Line;
typedef pair<Point ,R > Circle;
typedef vector<Point> Poly;

#define EPS (1e-10)//誤差
#define EQ(a,b) (abs((a)-(b)) < EPS)//２つの実数が等しいか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )//２つのベクトルが等しいか
#define ft first
#define sd second
#define pb push_back
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
 
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

R dot(Point a,Point b){//内積ok
    return (a.real() * b.real() + a.imag() * b.imag());
}
R cross(Point a,Point b){//外積ok
    return (a.real() * b.imag() - a.imag() * b.real());
}




bool is_orthogonal(Line a,Line b){//2直線の直行判定ok
    return EQ(dot(a.ft - a.sd,b.ft - b.sd),0.0);
}
bool is_parallel(Line a,Line b){//2直線の並行判定ok
    return EQ(cross(a.ft - a.sd,b.ft - b.sd),0.0);
}



////////////////////交差判定
int ccw(Point a,Point b,Point c){//ok
    b -= a; c -= a;
    if(cross(b,c) > EPS) return 1;//a→bで反時計周りに折れてb→c
    if(cross(b,c) < -EPS) return -1;//a→bで時計周りに折れてb→c
    if(dot(b,c) < -EPS) return 2;//c--a--b on same line
    if(norm(c) - norm(b) > EPS) return -2;//a--b--c(absじゃなくて二乗するのは差が出やすいから?)
    return 0;//a--c--bまたはb==c
}

bool is_intersection_ll(Line l,Line m){//２つの直線が交わるかok
    return abs(cross(l.sd - l.ft,m.sd - m.ft)) > EPS || //平行でない
        abs(cross(l.sd - l.ft,m.ft - l.ft)) < EPS; //平行だが同じ線
}

bool is_intersection_ls(Line l,Line s){//直線lと線分sが交わるか
    return cross(l.sd - l.ft, s.ft-l.ft)*       // s[0] is left of l
        cross(l.sd - l.ft, s.sd - l.ft) < EPS; // s[1] is right of l
}

bool is_intersection_lp(Line l,Point p){//直線lと点pが交わるか
    return abs(cross(l.sd - p,l.ft - p));
}

bool is_intersection_ss(Line a,Line b){//２つの線分が交わるかok
    return ccw(a.ft,a.sd,b.ft)*ccw(a.ft,a.sd,b.sd) <= 0 && ccw(b.ft,b.sd,a.ft)*ccw(b.ft,b.sd,a.sd) <= 0;
}

bool is_intersection_sp(Line s,Point p){//線分と点の交差判定 三角不等式の利用
    return abs(s.ft - p) + abs(s.sd - p) - abs(s.ft - s.sd) < EPS;
}


bool intersection_cc(Circle c1,Circle c2){//２つの円の交差判定ok
    return abs(c1.ft - c2.ft) - (c1.sd + c2.sd) < -EPS;
}


/////////////距離
R dis_lp(Line l,Point p){//直線lと点pの距離ok
    return abs(cross(l.sd - l.ft,p - l.ft)) / abs(l.sd - l.ft);
}

R dis_ll(Line l,Line m){//２つの直線の距離
    return is_intersection_ll(l,m) ? 0.0 : dis_lp(l,m.ft);
}

R dis_ls(Line l,Line s){//直線lと線分sの距離
    if(is_intersection_ls(l,s)) return 0.0;
    return min(dis_lp(l,s.ft),dis_lp(l,s.sd));
}

R dis_sp(Line s,Point p){//線分sと点pの距離ok
    if(dot(s.sd - s.ft,p - s.ft) < EPS) return abs(p - s.ft);
    if(dot(s.ft - s.sd,p - s.sd) < EPS) return abs(p - s.sd);
    return dis_lp(s,p);
}

R dis_ss(Line s,Line t){//２つの線分の距離ok
    if(is_intersection_ss(s,t)) return 0.0;
    return min(min(dis_sp(s,t.ft),dis_sp(s,t.sd)),
            min(dis_sp(t,s.ft),dis_sp(t,s.sd)));
}



//////////////射影と反射
Point projection(Line l,Point p){//射影を求めるok
    R t = dot(p - l.ft,l.ft - l.sd) / norm(l.ft - l.sd);
    return l.ft + t * (l.ft - l.sd);
}

Point reflection(Line l,Point p){//反射を求めるok
    return p + (R)2.0 * (projection(l,p) - p);
}




//////////////交点(交差する保証してないときは交差判定してからつかってね)

Point intersection_ll(Line l,Line m){//交差判定してるなら線分にも使えるok
    R A = cross(l.sd - l.ft,m.sd - m.ft);
    R B = cross(l.sd - l.ft,l.sd - m.ft);
    if(abs(A) < EPS && abs(B) < EPS) return m.ft;//同じ線
    //if(abs(A) < EPS)assert(false);//並行で交点なし
    return m.ft + B / A * (m.sd - m.ft);
}

Line intersection_of_two_circles(Circle c1,Circle c2){//ok ２つの円の交点をLineに入れて返す(r1 + r2 > sqrt((x1 - x2) ^ 2 + (y1 - y2) ^ 2))を満たす必要があるok
    R a =  abs(c2.ft - c1.ft);
    R b = c1.sd;
    R c = c2.sd;

    R rc = (a  * a + b * b - c * c) / (2.0 * a);
    R rs = sqrt(b * b - rc * rc);//C++ ではオーバーロードが可能であるため、sqrt または float 型を受け取る long double のオーバーロードを呼び出すことができます。 C プログラムでは、sqrt は常に double を受け取って返します。
    Point diff = (c2.ft - c1.ft) / a;

    Line p ;
    p.ft = c1.ft + diff * rc + diff * Point(0,1) * rs;
    p.sd = c1.ft + diff * rc + diff * Point(0,-1) * rs;

    return p;
}


/////////////////////////polygon

#define currP(P,i) P[(i) % P.size()]//今の頂点
#define nextP(P,i) P[((i) + 1)%P.size()]//次の頂点

int is_contains_p_in_Poly(Poly po,Point p){//点が多角形の内部(1)、境界(-1)、外部(0)のどこにあるかを判定ok
    bool in = false;
    REP(i,po.size()){
        Point a = currP(po,i) - p,b = nextP(po,i) - p;
        if(a.imag() > b.imag())swap(a,b);
        if(a.imag() < EPS && EPS < b.imag())
            if(cross(a,b) < -EPS) in = !in;
        if(EQ(cross(a,b),0.0) && dot(a,b) < EPS)return  -1;
    }
    return in;
}

R area2(Poly po){//多角形の面積の二倍を求めるok
    R A = 0.0;
    REP(i,po.size())
        A += cross(currP(po,i),nextP(po, i));
    return A;
}




///////////////////////////凸

bool comp_complex_real(Point a,Point b){//x→yの辞書順ok
    if(EQ(a.real(),b.real()))
        return b.imag() - a.imag() > EPS;
    return b.real() - a.real() > EPS;
}

Poly convex_hull(Poly ps){//凸包ok
    int n = ps.size(),k = 0;
    sort(ps.begin(),ps.end(),comp_complex_real);
    Poly ch(2*n);
    for(int i = 0;i < n;ch[k++] = ps[i++])// lower-hull
        while(k >= 2 && ccw(ch[k - 2],ch[k - 1],ps[i]) <= 0 && ccw(ch[k - 2],ch[k - 1],ps[i]) > -2) --k;//３つ目の条件は180度を含むときのみ必要
    for(int i = n - 2,t = k + 1;i >= 0;ch[k++] = ps[i--])//upper-hull
        while(k >= t && ccw(ch[k - 2],ch[k - 1],ps[i]) <= 0 && ccw(ch[k - 2],ch[k - 1],ps[i]) > -2) --k;//上に同じ
    ch.resize(k - 1);
    return ch;
}
#define prevP(P, i) P[(i+P.size()-1) % P.size()]
bool isconvex(Poly P){//凸性判定時計回り反時計周りに対応
    bool cl = false,ccl = false;
    for(int i = 0;i < P.size();++i){
        int c = ccw(prevP(P,i),currP(P,i),nextP(P,i));
        if(c == -2)continue;//180度を含むときのみ　360度も含むときはc == -2 || c == 0
        if(c == 1)ccl = true;
        else if(c == 2)cl = true;
        else return false;
    }
    return !(cl && ccl);
}

Point p[3],inp[3];
int ccc;

bool C(R x) {
    R a1 = abs(p[2] - p[1]);
    R b1 = abs(p[1]); 
    Point m1 = (b1 * (p[2] - p[1]) - a1 * p[1]) / (a1 + b1);
    Line l1 = Line(Point(0,0),p[2] - p[1]);
    R f1 = dis_lp(l1,m1);

    R a2 = abs(p[1] - p[2]);
    R b2 = abs(p[2]); 
    Point m2 = (b2 * (p[1] - p[2]) - a2 * p[2]) / (a2 + b2);
    Line l2 = Line(Point(0,0),p[1] - p[2]);
    R f2 = dis_lp(l2,m2);

    Point c1 = p[1] + (x / f1) * m1;
    Point c2 = p[2] + (x / f2) * m2;

    if(x > f1 || x > f2)
        return false;

    l1 = Line(p[0],p[2]);
    l2 = Line(p[0],p[1]);

    if(dis_lp(l1,c1) < x || dis_lp(l2,c2) < x){
        return false;
    } 

    return abs(c1 - c2) >= 2 * x;
}
int main(){

    REP(i,3) {
        int x,y;
        cin >> x >> y;
        inp[i] = Point(x,y);
    }

    R ans = 0;

    REP(i,3) {
        REP(j,3) {
            p[(i + j) % 3] = inp[j];
        }
        p[1] -= p[0];
        p[2] -= p[0];
        p[0] = Point(0,0);

        R l = 0,r = 1000000;
        while(r - l > 1e-12) {
            R mid = (r + l) / 2;
            if(C(mid)) {
                l = mid;
            }else {
                r = mid;
            }
        }
        ans = max(ans,r);
    }
    printf("%.12Lf\n",ans);
    return 0;
}

