// Kosaraju's algorithm for SCC

#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll N = 1e5 + 1;
vector<ll> adj[N], tadj[N];
bool vis[N];
vector<ll> order, scc;


void dfs1(int node){
	vis[node] = 1;
	for(auto child : adj[node]){
		if(vis[child] == 0)
			dfs1(child);
	}
	order.push_back(node);
} // order : reverse toposort

void dfs2(int node){
	vis[node] = 1;
	scc.push_back(node);
	for(auto child : tadj[node]){
		if(vis[child] == 0)
			dfs2(child);
	}
}

void solve(){
	ll n, m, a, b;
	cin >> n >> m;

	for(ll i = 0; i < m; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		tadj[b].push_back(a);
	}

	for(ll i = 0; i < n; i++){
		if(vis[i] == 0)
			dfs1(i);
	}
	for(ll i = 0; i < n; i++)
		vis[i] = 0;

	reverse(order.begin(), order.end());

	for(auto &x : order){
		if(vis[x] == 0){
			dfs2(x);
			// scc is strongly connected component
			// do the stuff of SCC
			for(auto i : scc) cout << i << " ";
			cout << '\n';
			scc.clear();
		}
	}
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
