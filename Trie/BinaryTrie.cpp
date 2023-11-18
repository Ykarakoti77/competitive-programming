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

// Binary Trie
const ll LOG = 20;

void solve() {
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (auto &i : v) cin >> i;

	vector<array<ll, 2>> vec({{ -1, -1}});

	auto add = [&] (ll x) {
		ll t = 0; 	// current node index
		for (ll i = LOG - 1; i >= 0; i--) {
			ll j = (x >> i) & 1;
			if (vec[t][j] == -1) { // child not present
				vec[t][j] = vec.size();  // vec[i][j] points to the index of next node.
				vec.push_back({ -1, -1}); // insert new node.
			}
			t = vec[t][j]; // update current node index.
		}
	};
	for (auto &i : v) add(i);
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
