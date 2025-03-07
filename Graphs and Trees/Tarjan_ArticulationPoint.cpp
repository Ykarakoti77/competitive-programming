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

//----------Tarjan's algorithm to find articulation points in a graph -------// 

ll n; 
vector<vector<ll>> adj;

vector<ll> cut_points;
vector<bool> visited;
vector<ll> tin, low;
ll timer;

void IS_CUTPOINT(ll v) {
    cut_points.push_back(v);
}

void dfs(ll v, ll p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    ll children=0;
    for (ll to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
                IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1)
        IS_CUTPOINT(v);
}

void find_cut_pointspolls() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
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