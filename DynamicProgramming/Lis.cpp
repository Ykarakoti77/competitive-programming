//  Longest Increasing Subsequence in O(nlogn)

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

ll findLis(vector<ll> &v) { 
    ll n = v.size();
    vector<ll> lis;
    vector<ll> addedAt(n);
    for(ll i = 0; i < n; i++) {
        if(lis.empty() || lis.back() < v[i]) {
            lis.push_back(v[i]);
            addedAt[i] = lis.size() - 1;
        }
        else { 
            auto it = lower_bound(all(lis), v[i]);
            *it = v[i];
            addedAt[i] = it - lis.begin();
        }
    }

    ll cur = lis.size() - 1;
    vector<ll> res;
    for(ll i = n - 1; i >= 0; i--) {
        if(addedAt[i] == cur) {
            res.push_back(v[i]);
            cur--;
        } 
        if(cur < 0) break;
    }
    reverse(all(res));
    return lis.size();
}

void solve(){
    vector<ll> v = {1, 5, 7, 10, 9, 6, 8, 9, 2, 3, 10};
    cout << findLis(v) << " "; 
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