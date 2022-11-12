// FenwickTree 
// Finding the sum of a range in O(log n) , updation in O(log n)

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct FenwickTree{
	vector<ll> bit;
	ll n;

	FenwickTree(ll n){
		this -> n = n;
		bit.assign(n, 0);
	}

	FenwickTree(vector<ll> a) : FenwickTree(a.size()) {
		for(size_t i = 0; i < a.size(); i++){
			add(i,a[i]);
		}
	}

	ll sum(ll r){
		int ret = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1)
			ret += bit[r];
		return ret;
	}

	ll sum(ll l, ll r) {
		return sum(r) - sum(l - 1);
	}

	void add(ll idx, ll delta){
		for(; idx < n; idx = idx | (idx + 1))
			bit[idx] += delta;
	}
};

void solve(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(auto &i : v) 
		cin >> i;
	FenwickTree fen = FenwickTree(v);
	ll l, r;
	cin >> l >> r;
	cout << fen.sum(l, r);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	ll t=1;
	// cin >> t;
	while(t--){
		solve();
	}
	return 0;
}
