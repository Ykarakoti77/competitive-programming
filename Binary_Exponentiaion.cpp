#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll M = 1e9 + 7;
const ll N = 1002;
ll fact[N];

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
    for (ll i = 1; i < n; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
}

ll nCr(ll n, ll r) {
    ll ans = (fact[n] * binpow(fact[r], M - 2) % M * binpow((fact[n - r]), M - 2) % M) % M;
    return ans;
}

/**/
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());
    ll num = v[n - k];
    ll cnt = 0, z = 0;
    for (ll i = 0; i < n; i++) {
        if (v[i] == num) cnt++;
        if (v[i] == num && i >= n - k) z++;
    }
    ll ways = nCr(cnt, z);
    cout << ways << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    facto(N);
    while (t--) {
        solve();
    }
    return 0;
}
