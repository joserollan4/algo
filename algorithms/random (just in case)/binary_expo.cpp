ll bpow(ll a, ll b) { // a**b
  if (b == 0) return 1;
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }  
    a = a * a;
    b >>= 1;
  }  
  return res;
}  

ll bpow_mod(ll a, ll b, ll m) { // a**b % m
  if (b == 0) return 1;
  ll res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a % mod;
    }  
    a = a * a % mod;
    b >>= 1;
  }  
  return res;
}  
