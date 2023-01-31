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

vector<vector<pair<ll, ll>>> adj;
vector<ll> dp;
vector<ll> vis;
vector<ll> cycle;

ll dfs(ll v) {
	vis[v] = 1;
	dp[v] = 0;
	cycle[v] = 1;   // if the graph was not DAG then this can detect cycle in directed graph
	for (auto &i : adj[v]) {
		if (cycle[i.first]) {  // checking if cycle is true in the recursive stack 
			return dp[v] = 1e18;
		}
		if (!vis[i.first]) { // don't run dfs again if vertex is visited
			dfs(i.first);
		}
		dp[v] = max(dp[v], i.second + dp[i.first]); // finds the longest path in dag
	}
	cycle[v] = 0;   // setting cycle to 0 again so that it gets reset for next time 
	return dp[v];
}

void solve() {
	ll n;
	cin >> n;
	adj.assign(n, vector<pair<ll, ll>>());
	dp.assign(n, 0);
	vis.assign(n, 0);
	cycle.assign(n, 0);
	vector<ll> st;
	for (ll i = 0 ; i < n; i++) {
		ll x; cin >> x;
		if (x == 0) st.push_back(i);
		for (ll j = 0; j < x; j++) {
			ll k;
			cin >> k; k--;
			ll w = 0;
			if (k > i) w = 1;
			adj[k].push_back({i, w}); // directed graph 
		}
	}
	ll ans = -1;
	for (ll i = 0; i < n; i++) {      // run dfs for all vertexes
		ans = max(ans, 1 + dfs(i));    // longest path in DAG
	}
	if (ans > 1e18) {
		cout << -1 << '\n';
		return;
	}
	cout << ans << '\n';
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

/*
code for this problem https://codeforces.com/contest/1572/problem/A

Idea : 
if the graph is cyclic then no answer was possible 
if if was DAG then longest path in the DAG was our answer

*/
