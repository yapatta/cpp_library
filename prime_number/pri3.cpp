#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> ps;

bool IsPrime(int x){
  if(x<2) return false;
  if(x==2) return true;
  for(int i=3;i*i<=x;i+=2){
    if(x%i == 0) return false;
  }
  return true;
}
bool orPrime(int x){
  for(int i=0;i<ps.size();i++){
    int prime = ps[i];
    if(prime*prime>x) return true;
    if(x%prime == 0) return false;
  }
  return true;
}

int main(){
  for(int i=2;i<=10000;i++){
    if(IsPrime(i)){
      ps.push_back(i);
    }
  }

  int n,cnt = 0;
  cin >> n;
  for(int i=0;i<n;i++){
    int tmp;
    cin >> tmp;
    if(orPrime(tmp)) cnt++;
  }
  cout << cnt << endl;
}
