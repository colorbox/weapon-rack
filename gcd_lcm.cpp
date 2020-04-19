int gcd(int a, int b){
  if(a==1 || b==1)return 1;
  if (a < b)swap(a,b);
  
  return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b){
  return a * b / gcd(a, b);
}

ll gcd(ll a, ll b){
  if(a==1 || b==1)return 1;
  if (a < b)swap(a,b);
  
  return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b){
  return a * b / gcd(a, b);
}
