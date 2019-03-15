#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(int (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
const ll MOD=1e9+7;
using namespace std;
static const int N = 105;
static const int INF = INT_MAX;

int n;
bool M[N][N];
int d[N],f[N]; //距離の訪問状態を管理
//d[i]=INFのとき: 未発見
//d[i].first: 発見時刻
//d[i].second: 完了時刻

void dfs(int t){
  stack<int> s;
  s.push(t);
  rep(i,n) d[i] = f[i] = INF;
  d[0] = 1;
  int count=1;
  int u;
  while(!s.empty()){
    u = s.top();
    int v;
    for(v=0;v<n;v++){
      if(!M[u][v]) continue;
      if(d[v] != INF) continue;

      //隣接してかつ未探索の場合
      d[v] = count + 1;
      count++;
      s.push(v);
      break;
    }
    //隣接してかつ未探索の点が存在しない
    if(v==n){
      f[u] = count + 1;
      count++;
      s.pop();
    }

  }
  for(int i=0;i<n;i++){
    cout << i+1 << " " << d[i] << " " << f[i] << endl;
  }
}

int main(){
  int u,k,v;
  cin >> n;
  //初期化
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
  dfs(0);
}
