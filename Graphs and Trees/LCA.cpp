#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX_N = 1e4; // n is the number of vertex
const ll LOG = 20;    // 2^ LOG		
vector<ll> adj[MAX_N];
ll up[MAX_N][LOG];
ll depth[MAX_N];

void dfs(ll a, ll p){
    for(ll b : adj[a]){
	  if(b == p) continue;
        depth[b] = depth[a] + 1;
	  up[b][0] = a;
        for(ll i = 1; i < LOG; i++){
            up[b][i] = up[up[b][i-1]][i-1];
        }
        dfs(b, a);
    }
}

int get_lca(ll a, ll b){
    if(depth[a] < depth[b]){
        swap(a, b);
    }

    // Get to the same depth
    ll k = depth[a] - depth[b];
    for(ll i = LOG - 1; i >= 0; i--){
        if(k & (1 << i)){
            a = up[a][i];
        }
    }

    // checking if a is the LCA
    if(a == b){
        return a;
    }

    // getting to the last ancestor which is not lca
    for(ll i = LOG - 1; i >=0; i--){
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    // LCA is the parent of a
    return up[a][0];
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
