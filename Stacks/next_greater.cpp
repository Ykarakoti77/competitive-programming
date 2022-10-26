#include<bits/stdc++.h>
using namespace std;
#define ll long long

void nextGreater(vector<ll> &v, vector<ll> &next_greater){ // declare next_greater vector with -1 initially
	ll n = v.size();
	stack<ll> s;
	s.push(0);

	for(ll i = 1; i < n; i++){
		if(s.empty()){
			s.push(i);
			continue;
		}
		while(!s.empty() && v[s.top()] < v[i]){ // just change the comparator of '>' for next smaller element  
			next_greater[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
}

void prevGreater(vector<ll> &v, vector<ll> &prev_greater){
	ll n = v.size();
	stack<ll> s;
	s.push(n-1);
	for(ll i = n - 2; i >= 0; i--){
		if(s.empty()){
			s.push(i);
			continue;
		}
		while(!s.empty() && v[s.top()] < v[i]){  // change comparator to '>' for previous smaller element
			prev_greater[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
}

void solve(){
	ll n;
	cin >> n;
	vector<ll> v(n);
	for(auto &i : v) cin >> i;
	vector<ll> next_greater(n, -1), prev_greater(n, -1);
	nextGreater(v, next_greater);
	prevGreater(v, prev_greater);
	for(auto &i : next_greater) cout << i << " ";
	cout << '\n';
	for(auto &i : prev_greater) cout << i << " ";
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
