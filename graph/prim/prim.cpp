#include <bits/stdc++.h>
using ll = long long;
using namespace std;
static const ll MAX = 100;
static const ll INF = LLONG_MAX;
static const ll WHITE = 0;
static const ll GRAY = 1;
static const ll BLACK = 2;

ll n, M[MAX][MAX];

ll prim(){
  ll u,minv;
  //d[i]: iに隣接&未探索の点への重みが最小な辺の重み
  //p[i]:iの親
  //WHITE: 未探索, BLACK: 探索済み
  ll d[MAX],p[MAX],color[MAX];

  for(int i=0;i<n;i++){
    d[i] = INF;
    p[i] = -1;
    color[i] = WHITE;
  }

  d[0] = 0;

  while(1){
    minv = INF;
    u = -1;
    for(int i=0;i<n;i++){
      if(minv > d[i] && color[i] != BLACK){
        minv = d[i];
        u = i;
      }
    }
    //全て探索完了
    if(u == -1) break;
    color[u] = BLACK;

    for(int v=0;v<n;v++){
      if(color[v] != BLACK && M[u][v] != INF){
        if(d[v] > M[u][v]){
          d[v] = M[u][v];
          p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
  ll sum = 0;
  for(int i=0;i<n;i++){
    if(p[i] != -1) sum += M[i][p[i]];
  }
  return sum;
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      ll tmp;
      cin >> tmp;
      M[i][j] = (tmp == -1) ? INF : tmp;
    }
  }
  cout << prim() << endl;
}
