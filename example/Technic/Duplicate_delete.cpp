//vectorの数列の重複を削除する
//O(nlogn)
//参考 https://qiita.com/ysk24ok/items/30ae72f4f1060b088588

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    vector<int> vec = {10,40,40,20,20,30,20,20,40};

    //　ここからテクニック
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    //ここまで

    for(auto v : vec) {
        cout << v << " ";
    }
    cout << endl;
}