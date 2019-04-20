#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define reps(i,s,n) for(int (i)=(s);(i)<(n);++(i))
#define rep(i,n) reps(i,0,n)
#define reptr(i,n) for(int (i)=(n);(i)>=0;--(i))
#define All(x) (x).begin(),(x).end()
#define mp make_pair
const ll MOD=1e9+7;
const ll MAX=1e8+7;
using namespace std;
int n;
bool IsPrime[10005];
//判定する対象の素数
int M[10005];

void eratos(){
  for(int i=2;i<=10000;i++){
    if(IsPrime[i]){
      int j = i + i;
      while(j <= 10000){
        IsPrime[j] = false;
        j += i;
      }
    }
  }
}

bool OrPrime(int x){
  if(x<2) return false;
  if(x==2) return true;
  if(x%2==0) return false;
  for(int i=3;i<=10000;i+=2){
    if(!IsPrime[i]) continue;
    if(i*i>x) return true;
    if(x%i==0) return false;
  }
  return true;
}

int main(){
  cin >> n;
  rep(i,n){
    cin >> M[i];
  }
  for(int i=0;i<=10000;i++){
    IsPrime[i] = true;
  }
  IsPrime[0] = IsPrime[1] = false;
  eratos();
  int cnt = 0;
  rep(i,n){
    if(OrPrime(M[i])) cnt++;
  }
  cout << cnt << endl;
}
