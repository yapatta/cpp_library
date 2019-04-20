#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int num=0;
  while(num<=50){
    int data[100]={0};
    int a,b;
    while(1){
      cin >> a >> b;
      num++;
      if(a==0 && b==0){
        break;
      }
      data[a]++;
      data[b]++;
    }

    int odd=0,even=0;
    for(int i=1;i<=50;i++){
      if(data[i]>0){
        if(data[i]%2==1){
          odd++;
        }
      }
    }
    if(odd == 2) cout << "OK" << endl;
    else cout << "NG" << endl;
  }
}
