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

int n;
int M[MAX][MAX];

void prim(){
  int color[MAX];
  //d[i] : 自集合からの点iへの最短距離
  int d[MAX];
  //p[i]=s iの親はs
  int p[MAX];
  rep(i,n){
    color[i] = WHITE;
    d[i] = INT_MAX;
    p[i] = -1;
  }
  d[0] = 0;

  while(1){
    int u = -1,minv = INT_MAX;
    rep(i,n){
      if(color[i] != BLACK && minv > d[i]){
        u = i;
        minv = d[i];
      }
    }
    if(u == -1) break;
    color[u] = BLACK;
    rep(v,n){
      if(M[u][v] != INT_MAX && color[v] != BLACK){
        if(d[v] > M[u][v]){
          d[v] = M[u][v];
          p[v] = u;
          color[v] = GRAY;
        }
      }
    }
  }
  int sum = 0;
  rep(i,n){
    //iの親が存在しないことはもしかしたらあるかもしれない
    //全域木探索だから、ないとは思うが
    if(p[i] != -1) sum += M[i][p[i]];
  }
  cout << sum << endl;
}

int main(){
  cin >> n;
  rep(i,n){
    rep(j,n){
      int tmp;
      cin >> tmp;
      M[i][j] = (tmp == -1) ? INT_MAX : tmp;
    }
  }
  prim();
}
