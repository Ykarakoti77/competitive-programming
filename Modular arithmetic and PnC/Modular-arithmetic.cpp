
/*/-----------------------Modular Arithmetic / PnC ---------------/*/
#define ll long long

const ll M = 1e9 + 7;
const ll N = 300005;
ll fact[N];
ll ifact[N];

inline ll add(ll x, ll y) {
	x += y;
	if (x >= M) return x - M;
	return x;
}
inline ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + M;
	return x;
}
inline ll mul(ll x, ll y) {
	return (x * 1ll * y) % M;
}
inline ll power(ll x, ll y) {
	ll ans = 1;
	while (y) {
		if (y & 1) ans = mul(ans, x);
		x = mul(x, x);
		y >>= 1;
	}
	return ans;
}
inline ll inverse(ll x) {
	return power(x, M - 2);
}
inline ll nCr(ll n, ll r) {
	return mul(fact[n], mul(ifact[r], ifact[n - r]));
}

void facto() {
	fact[0] = 1;
	for (ll i = 1; i < N; i++) {
		fact[i] = mul(fact[i - 1], i);
    }
}
void ifacto() {
	ifact[0] = 1;
	ifact[N - 1] = inverse(fact[N - 1]);
	for (ll i = N - 1; i > 0; i--) {
		ifact[i - 1] = mul(ifact[i], i);
    }
}
