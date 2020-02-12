// x^n in mod
ll modpow(ll x, ll n, ll mod){
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

// nCr in mod
ll comb(ll n, ll r){
  if(n<0 || n<r || r<0)return 0;
  ll fn = fac(n);
  ll fr = fac(r);
  ll fn_r = fac(n-r);
  
  ll d = (modpow(fr, MOD-2, MOD) * modpow(fn_r, MOD-2, MOD)) % MOD;
  ll u = fn%MOD;
  
  ll result = u * d % MOD;
 
  return result;
}

facs[0]=1;
rep(i, n+10)facs[i+1] = (facs[i]*(i+1))%MOD;
