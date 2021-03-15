ll facs[MAXN];
ll rfacs[MAXN];

// x^n in mod
ll modpow(ll x, ll n, ll mod=MOD){
  if(n==0) return 1;

  if(n%2==0){
    return modpow(x*x%mod, n/2, mod) % mod;
  }else{
    return x * modpow(x, (n-1), mod) % mod;
  }
}

// n! in mod
ll fac(ll n){
  return facs[n];
}
// n!^(-1) in mod
ll rfac(ll n){
  return rfacs[n];
}

// nCr in mod
ll comb(ll n, ll r){
  if(n<0 || n<r || r<0)return 0;
  ll fn = fac(n);
  ll fr = rfac(r);
  ll fn_r = rfac(n-r);
  
  ll d = fr * fn_r % MOD;
  ll u = fn%MOD;
  
  ll result = u * d % MOD;
 
  return result;
}

// nPr in  mod
ll perm(ll n, ll r){
  if(n<0 || n<r || r<0)return 0;
  ll fn = fac(n);
  ll fn_r = rfac(n-r);
  
  ll d = fn_r;
  ll u = fn%MOD;
  
  ll result = u * d % MOD;
 
  return result;
}

ll homogeneous(ll n, ll r){
  return comb(n+r-1, r);
}

void init(){
  facs[0]=1;
  rep(i, MAXN-1)facs[i+1] = (facs[i]*(i+1))%MOD;
  rfacs[MAXN-1] = modpow(fac(MAXN-1), MOD-2, MOD);
  rrep(i, MAXN) rfacs[i-1] = rfacs[i] * i % MOD;
}
