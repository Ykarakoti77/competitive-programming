const ll M = 998244353;
const ll N = 3000007;
ll fact[N];
ll inv[N];
 
ll binpow(ll a, ll b) {  // for calculating inverse use binpow(a, M-2);
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % M;
		a = (a * a) % M;
		b >>= 1;
	}
	return res;
}
void facto(ll n) {
	fact[0] = 1;
	for (ll i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % M;
	}
}
// we can also precompute inverse rather then computing it when using nCr
void inverse(ll n) {
	inv[0] = 1;
	inv[n] = binpow(fact[n], M - 2);
	for (ll i = n; i > 0; i--){
		inv[i - 1] = (inv[i] * i) % M;
	}
}
 
ll nCr(ll n, ll r) {
	ll ans = (fact[n] * inv[r] % M * inv[n - r] % M) % M;
	return ans;
}
