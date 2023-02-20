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


// node stores the sum of range from st to en
// [st, en] range in segment tree
// [l, r] range that we want to query on in the given array
// --> 0 based indexing

struct SegTree {
	ll n, s;
	vector<ll> seg, arr;

	SegTree(vector<ll> &a, ll tree_len) { // array and its length
		arr = a;
		n = tree_len;
		s = 1;
		while (s < 2 * n) { // s : size of segtree
			s = s << 1;
		}
		seg.assign(s, 0); // default value (sum) = 0
		build(0, 0, n - 1);
	}

	void build(ll node, ll st, ll en) {
		if (st == en) {
			seg[node] = arr[st];
			return;
		}
		ll mid  = (st + en) / 2;
		build(2 * node + 1, st, mid);
		build(2 * node + 2, mid + 1, en);
		seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
	}

	void update(ll node, ll st, ll en, ll pos, ll val) {
		if (st == en) {
			seg[node] = arr[st] = val;
			return;
		}
		ll mid = (st + en) / 2;
		if (pos <= mid) update(2 * node + 1, st, mid, pos, val);
		else update(2 * node + 2, mid + 1, en, pos, val);
		seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
	}

	ll query(ll node, ll st, ll en, ll l, ll r) {
		if (st >= l && en <= r) return seg[node];
		if (en < l || st > r) return 0;
		ll mid = (st + en) / 2;

		ll left = query(2 * node + 1, st, mid, l, r);
		ll right = query(2 * node + 2, mid + 1, en, l, r);
		return left + right;
	}

	void make_update(ll pos, ll val) {
		update(0, 0, n - 1, pos, val);
	}
	ll make_query(ll l, ll r) {
		return query(0, 0, n - 1, l, r);
	}
};

void solve() {
	ll n, m;
	cin >> n >> m;
	vector<ll> v(n);
	for (ll i = 0; i < n; i++) cin >> v[i];

	SegTree seg(v, n);
	while (m--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			seg.make_update(b, c);
		}
		else {
			ll res = seg.make_query(b, c  - 1);
			cout << res << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
