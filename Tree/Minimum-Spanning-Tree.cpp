#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct DSU
{
    vector<ll> parent, siz; 
    DSU(ll n) : parent(n), siz(n, 1) { iota(parent.begin(), parent.end(), 0ll); }

    ll find(ll v){  // to find the set representative
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }
    void merge(ll a, ll b){
        a = find(a);
        b = find(b);
        if(a != b){
            if(siz[a] < siz[b]){
                swap(a, b);
            }
            parent[b] = a;
            siz[a] += siz[b];
        }
    }
    ll size(ll x) { return siz[find(x)]; } // size of the set
};

// KRUSKAL'S ALGORITHM FOR MST

ll spanningTree(ll N, vector<vector<ll>> &edges){

	sort(edges.begin(), edges.end(), [](vector<ll> &a, vector<ll> &b) { return a[2] < b[2];} );

	DSU mds(N);
	ll mst = 0;

	for(auto x : edges){
		ll u = x[0];
		ll v = x[1];
		ll w = x[2];

		u = mds.find(u);
		v = mds.find(v);
		if(u != v){
			mds.merge(u, v);
			mst += w;
		}
	}
	return mst;
}

void solve(){
	ll  n, m;
	cin >> n >> m;
	vector<vector<ll>> edges(m, vector<ll> (3));
	for(ll i = 0; i < m; i++){
		ll x, y, wt;
		cin >> x >> y >> wt;
		x--, y--;
		edges[i][0] = x;
		edges[i][1] = y;
		edges[i][2] = wt; 
	}
	cout << spanningTree(n, edges) << '\n';
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
