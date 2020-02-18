map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (int i = 2; i * i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
  return res;
}
