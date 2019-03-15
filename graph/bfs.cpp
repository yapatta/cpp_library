#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(int (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define MAX 1005
const ll MOD=1e9+7;
using namespace std;
static const int N = 100;
static const int INF = INT_MAX;

int n;
bool M[N][N];
int d[N]; //距離の訪問状態を管理

void bfs(int s){
  queue<int> q;
  q.push(s);
  rep(i,n) d[i]=INF;
  d[s]=0;
  int u;
  while(!q.empty()){
    u = q.front();
    q.pop();
    for(int v=0;v<n;v++){
      if(!M[u][v]) continue;
      if(d[v] != INF) continue;
      d[v]=d[u]+1;
      q.push(v);
    }
  }
  for(int i=0;i<n;i++){
    cout << i+1 << " " << ((d[i] == INF) ? (-1) : d[i] ) << endl;
  }
}

int main(){
  int u,k,v;
  cin >> n;
  rep(i,n){
    rep(j,n){
      M[i][j]=false;
    }
  }
  rep(i,n){
    cin >> u >> k;
    u--;
    rep(j,k){
      cin >> v;
      v--;
      M[u][v]=true;
    }
  }
  bfs(0);
}
