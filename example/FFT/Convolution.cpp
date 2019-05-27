#include<iostream>
#include<complex>

using namespace std;

#define rep(i,n) for(ll i=0;i<(n);i++)

typedef long long ll;
typedef double R;
typedef complex<R> C;

void bitrev(C a[],ll N,ll index){
	C *b = (C*)malloc(N * sizeof(C));
	rep(i,N){
		ll k = 0,l = i;
		rep(j,index){
			k *= 2;
			k += (l & 1);
			l /= 2;
		}
		b[k] = a[i];
	}
	rep(i,N){
		a[i] = b[i];
	}
	free(b);
}

void saikifft(C a[],ll N,R sg){
	if(N == 1)
		return;
	rep(i,N / 2){
		a[i] += a[i + N / 2];
	}
	rep(i,N / 2){
		a[i + N / 2] = a[i] - 2.0 * a[i + N / 2];
		a[i + N / 2] *= C(cos(sg * 2.0 * M_PI * i / N),sin(sg * 2.0 * M_PI * i / N));
	}
	saikifft(a,N / 2,sg);
	saikifft(a + N / 2,N / 2,sg);
}

int fft(C a[],ll n){
	int N = 2,index = 1;;
	while (n > N){
		N *= 2;
		index++;
	}
	saikifft(a,N,-1.0);
	bitrev(a,N,index);
	return N;
}
int refft(C a[],ll n){
	int N = 2,index = 1;;
	while (n > N){
		N *= 2;
		index++;
	}
	saikifft(a,N,1.0);
	bitrev(a,N,index);
	rep(i,N)
		a[i] /= (R)N;
	return N;
}

int convolution(ll a[],ll b[],ll c[],int n){
	n *= 2;
	int N = 2,index = 1;;
	while (n > N){
		N *= 2;
		index++;
	}
	C *ac = (C*)malloc(N * sizeof(C));
	C *bc = (C*)malloc(N * sizeof(C));
	rep(i,N){
		ac[i] = C((i < n / 2) ? a[i] : 0.0,0.0);
		bc[i] = C((i < n / 2) ? b[i] : 0.0,0.0);
	}
	fft(ac,N);fft(bc,N);
	rep(i,N)
		ac[i] *= bc[i];
	refft(ac,N);
	rep(i,N)
		c[i] = ac[i].real() + 0.01;
	free(ac);free(bc);
	return N;
}


ll n;
ll a[100001],b[100001],c[200001];

int main() {
	cin >> n;

	rep(i,n)cin >> a[i+1] >> b[i+1];//a[0] = b[0] = 0とする

	convolution(a,b,c,n+1);//0〜nのn+1個

	rep(i,2*n) cout << c[i+1] << endl;//和がkとなる組み合わせがc[k]個
}