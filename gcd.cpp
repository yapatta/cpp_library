ll gcd(ll a, ll b) {
  if(a==0) return b;
  if(a>b) return gcd(a%b, b);
  else return gcd(b%a, a);
}
ll lcm(ll a, ll b) {
  ll tmp=gcd(a,b);
  return (a/tmp)*(b/tmp)*tmp;
}

int gcd(int a, int b) {
  if(a==0) return b;
  if(a>b) return gcd(a%b, b);
  else return gcd(b%a, a);
}
int lcm(int a, int b) {
  int tmp=gcd(a,b);
  return (a/tmp)*(b/tmp)*tmp;
}
