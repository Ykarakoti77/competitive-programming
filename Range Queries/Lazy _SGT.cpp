// Code for Lazy segment tree 
// # range updates

#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename Node, typename Update>
struct LazySGT {
	vector<Node> tree;
	vector<bool> lazy;
	vector<Update> updates;
	vector<ll> arr; 
	ll n;
	ll s;
	LazySGT(int a_len, vector<ll> &a) {
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n) {
			s = s << 1;
		}
		tree.resize(s); fill(tree.begin(), tree.end(), Node());
		lazy.resize(s); fill(lazy.begin(), lazy.end(), false);
		updates.resize(s); fill(updates.begin(), updates.end(), Update());
		build(0, n - 1, 1);
	}
	void build(ll start, ll end, ll index) { // Never change this
		if (start == end) {
			tree[index] = Node(arr[start]);
			return;
		}
		ll mid = start + (end - start) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}

	void pushdown(ll index, ll start, ll end) {
		if(lazy[index]){
			ll mid = start + (end - start) / 2;
			apply(2 * index, start, mid, updates[index]);
			apply(2 * index + 1, mid + 1, end, updates[index]);
			updates[index] = Update();
			lazy[index] = 0;
		}
	}
	void apply(ll index, ll start, ll end, Update& u){
		if(start != end){
			lazy[index] = 1;
			updates[index].combine(u, start, end);
		}
		u.apply(tree[index], start, end);
	}

	void update(ll start, ll end, ll index, ll left, ll right, Update& u){ // Never change
		if(start > right || end < left) 
			return;
		if(start >= left && end <= right){
			apply(index, start, end, u);
			return;
		}
		pushdown(index, start, end);
		ll mid = start + (end - start) / 2;
		update(start, mid, 2 * index, left, right, u);
		update(mid + 1, end, 2 * index + 1, left, right, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(ll start, ll end, ll index, ll left, ll right) { // Never change
		if(start > right || end < left)
			return Node();
		if(start >= left && end <= right){
			pushdown(index, start, end);
			return tree[index];
		}
		pushdown(index, start, end);
		ll mid = start + (end - start) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}
	void make_update(int left, int right, ll val) {
		Update new_update = Update(val); // may change
		update(0, n - 1, 1, left, right, new_update);
	}
	Node make_query(int left, int right) {
		return query(0, n - 1, 1, left, right);
	}
};

struct Node1{
	ll val; // may change
	Node1() { // Identity element
		val = 0;
	}
	Node1(ll p1) { // Actual Node
		val = p1; // may change
	}
	void merge(Node1 &l, Node1 &r){
		val = l.val + r.val;
	}
};

struct Update1{
	ll val;
	Update1(){ // Identity element
		val = 0;
	}
	Update1(ll val1) {
		val = val1;
	}
	void apply(Node1 &a, ll start, ll end) { // apply update to given node
		a.val = val * (end - start + 1);
	}
	void combine(Update1& new_update, ll start, ll end) {
		val = new_update.val;
	}
};

void solve(){
	vector<ll> arr = {100, 3, 5, 2, 6, 9};
	LazySGT<Node1, Update1> lazy = LazySGT<Node1, Update1>(6, arr);
	cout << lazy.make_query(0, 5).val << '\n';
	lazy.make_update(3, 4, 1);
	cout << lazy.make_query(0, 5).val << '\n';  
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
