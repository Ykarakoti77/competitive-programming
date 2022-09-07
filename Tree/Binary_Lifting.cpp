#include<bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAX_N = 1e4;
const ll LOG = 14;
vector<ll> children[MAX_N];
ll up[MAX_N][LOG]; // up[v][j] if 2^j-th ancestor of v;
ll depth[MAX_N];

void dfs(int a){
    for(auto b: children[a]){
        depth[b] = depth[a] + 1;
	  up[b][0] = a;
        for(ll j = 1; j < LOG; j++){
            up[b][j] = up[up[b][j-1]][j-1];
        }
        dfs(b);
    }
}

int getKthAncestor(int node, int k){
    if(depth[node] < k){
        return -1;
    }
    
    for(int i = LOG -1; i >= 0; i--){
        if(k & (1 << i)){
            node = up[node][i];
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    return 0;
}
