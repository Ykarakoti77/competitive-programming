#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x) (x).begin(), (x).end()

template<class T> 
using ordered_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

// https://codeforces.com/contest/732/problem/F

//----------Tarjan's algorithm to find bridges in a graph -------// 

set<pair<ll,ll>> bridges;

void IS_BRIDGE(ll v,ll to) {
    bridges.insert({v, to});
}

ll n;
vector<vector<ll>> adj; 
vector<bool> visited;
vector<ll> tin, low;
ll timer;

void dfs(ll v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;
    for (ll to : adj[v]) {
        if (to == p && !parent_skipped) {
            parent_skipped = true;
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}

void solve(){
    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    ll t=1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}