#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x) (x).begin(), (x).end()

template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

vector<ll> manacher_odd(string s) {
	ll n = s.size();
	s = "$" + s + "^";
	vector<ll> p(n + 2);
	ll l = 1, r = 1;
	for (ll i = 1; i <= n; i++) {
		p[i] = max(0ll, min(r - i, p[l + (r - i)]));
		while (s[i - p[i]] == s[i + p[i]]) {
			p[i]++;
		}
		if (i + p[i] > r) {
			l = i - p[i], r = i + p[i];
		}
	}
	return vector<ll>(begin(p) + 1, end(p) - 1);
}

vector<ll> manacher(string s) {
	string t;
	for (auto c : s) {
		t += string("#") + c;
	}
	auto res = manacher_odd(t + "#");
	return vector<ll>(begin(res) + 1, end(res) - 1);
}

void solve() {
	ll n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<ll> v = manacher(s);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}