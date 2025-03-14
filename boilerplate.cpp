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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<> distr(0, 2); // range

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