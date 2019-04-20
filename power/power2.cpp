#include <bits/stdc++.h>
using ll = long long;
using namespace std;
const ll  MOD = 1e9+7;

ll power(ll a,ll n){
  ll res = 1;
  if(n > 0){
    res = power( (a*a)%MOD, n/2);
    if(n%2 == 0) res = (res*res) % MOD;
    else res = (res)
  }
  return res;
}

int main(){
  ll m,n;
  cin >> m >> n;
  cout << power(m,n) << endl;
}
