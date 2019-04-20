#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind{
private:
  vector<ll> data;
public:
  UnionFind(ll x){
    data.resize(x,-1);
  }
  //data[x]はxの根の値
  //xが根の場合data[x]は根がxの集合の要素の個数
  ll root(ll x){
    return (data[x]<0) ? x : data[x] = root(data[x]);
  }
  void unite(ll x, ll y){
    x = root(x);
    y = root(y);
    if(x == y) return;
    //xにyを結合
    data[x] += data[y];
    data[y] = x;
  }
  bool same(ll x, ll y){
    return (root(x) == root(y));
  }
  ll size(ll x){
    return -data[root(x)];
  }
};

int main(){
  ll n,q;
  cin >> n >> q;
  UnionFind uf(n);
  for(int i=0;i<q;i++){
    ll com,x,y;
    cin >> com >> x >> y;

    if(com == 0){
      uf.unite(x,y);
    }else{
      if(uf.same(x,y)) cout << 1 << endl;
      else cout << 0 << endl;
    }
  }
}
