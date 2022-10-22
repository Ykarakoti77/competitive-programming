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

void solve(){
    DSU a(10), b(5);
    a.merge(1, 3);
    a.merge(2, 3);
    cout << a.find(4);
    cout << '\n';
    b.merge(3, 4);
    cout << b.find(3) << '\n';
    cout << b.find(2) << '\n';
    cout << b.size(2) << '\n';
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
