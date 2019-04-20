#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(int (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define mp make_pair
const ll MOD=1e9+7;
const int MAX = 100;
const int BLACK = 2;
const int GRAY = 1;
const int WHITE = 0;
using namespace std;

int n, M[MAX][MAX];

void dijkstra(){
  int minv;
  int color[MAX];
  //d[i] : 自集合からの点iへの最短距離
  int d[MAX];

  rep(i,n){
    color[i] = WHITE;
    d[i] = INT_MAX;
  }
  d[0] = 0;
  color[0] = GRAY;

  while(1){
    minv = INT_MAX;
    int u = -1;
    rep(i,n){
      if(color[i] != BLACK && minv > d[i]){
        u = i;
        minv = d[i];
      }
    }
    if(u == -1) break;
    color[u] = BLACK;
    rep(v,n){
      //uとvがつながっている、かつvが未探索
      if(M[u][v] != INT_MAX && color[v] != BLACK){
        if(d[v] > d[u] + M[u][v]){
          d[v] = d[u] + M[u][v];
          color[v] = GRAY;
        }
      }
    }
  }
  rep(i,n){
    cout << i << " " << (d[i] == INT_MAX ? -1 : d[i]) << endl;
  }
}

int main(){
  cin >> n;
  rep(i,n){
    rep(j,n){
      M[i][j] = INT_MAX;
    }
  }

  rep(i,n){
    int u,k;
    cin >> u >> k;
    rep(j,k){
      int v,c;
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  dijkstra();
}
