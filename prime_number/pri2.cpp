#include <bits/stdc++.h>
using namespace std;

vector<int> ps;
void set_prime(int n){
	for(int i=2;i*i<=n;i++){
		if(n%i==0)return;
	}
	ps.push_back(n);
}

//n以下の素数で割り切れないなら, nは素数である
bool is_prime(int n){
	if(n<2)return false;
	for(int i=0;i<ps.size();i++){
		int a=ps[i];
		if(a*a>n)return true;
		if(n%a==0)return false;
	}
	return true;
}

int main(){
	for(int i=2;i<10000;i++){
    //もし偶数ならばpsにpush
		set_prime(i);
		//10000までの素数をpsにpush
	}
	int n,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		ans += (is_prime(a) ? 1 : 0);
	}
	printf("%d\n",ans);
}
