#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll  MOD = 1e9+7;

ll power(ll a,ll n){
  ll cnt = 0,ans = 1;
  while(n > 0){
    if(n == 1) {
      ans *= a;
      ans %= MOD;
      break;
    }
    ll key = 1,tmpM = a;
    while(key*2 <= n){
      cnt++;
      key *= 2;
      tmpM = tmpM*tmpM;
      tmpM %= MOD;
    }
    ans *= tmpM;
    ans %= MOD;
    n -= key;
  }
  return ans;
}

int main(){
  ll m,n;
  cin >> m >> n;
  cout << power(m,n) << endl;
}
