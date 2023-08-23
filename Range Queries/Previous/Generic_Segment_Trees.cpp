#include<bits/stdc++.h>
using namespace std;
#define ll long long

template<typename Node, typename Update>
struct SegTree {
	vector<Node> tree; // tree of data type Node
	vector<ll> arr; // original array
	int n; // elements in original array
	int s; // size of tree
	SegTree(int a_len, vector<ll> &a) {
		arr = a;
		n = a_len;
		s = 1;
		while(s < 2 * n){   // finding the size of Tree 
			s = s << 1;		// first power of >= 2 * n 		
		}
		tree.resize(s);
		fill(tree.begin(), tree.end(), Node());
		build(0, n - 1, 1);
	}

	void build(int start, int end, int index) {  // never change this
		if(start == end) {
			tree[index] = Node(arr[start]);
			return;
		}
		int mid = start + (end - start) / 2;
		build(start, mid, 2 * index);
		build(mid + 1, end, 2 * index + 1);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	void update(int start, int end, int index, int query_index, Update &u){
		if(start == end){
			u.apply(tree[index]);
			return;
		}
		int mid = start + (end - start) / 2;
		if(mid >= query_index)
			update(start, mid, 2 * index, query_index, u);
		else 
			update(mid + 1, end, 2 * index + 1, query_index, u);
		tree[index].merge(tree[2 * index], tree[2 * index + 1]);
	}
	Node query(int start, int end, int index, int left, int right) {
		if (start > right || end < left) 
			return Node();
		if (start >= left && end <= right)
			return tree[index];
		int mid = start + (end - start) / 2;
		Node l, r, ans;
		l = query(start, mid, 2 * index, left, right);
		r = query(mid + 1, end, 2 * index + 1, left, right);
		ans.merge(l, r);
		return ans;
	}

	void make_update(int index, ll val) { // call update function for updating the segment tree
		Update new_update = Update(val);
		update(0, n - 1, 1 ,index, new_update);
	}
	Node make_query(int left, int right){ // call make_query function for querying in the segment tree
		return query(0, n -1, 1, left, right);
	}
};

// Node1 stores the data of a particular node in a segment tree 
struct Node1{   
	ll val; // May change
	Node1() {  // identity element
		val = INT_MAX;  
	}
	Node1(ll p1) { // actual node  
		val = p1;
	}
	void merge(Node1 &l, Node1 &r) {  // merge two child nodes
		val = min(l.val, r.val); // may change
	}
};

// Updates1 does the update in a segment tree
struct Update1 {
	ll val;
	Update1(ll p1) {
		val = p1;
	}
	void apply(Node1 &a){  // apply update to given node
		a.val = val; // may change
	}
};

void solve(){
	ll n, m;
	cin >> n >> m;
	vector<ll> v(n, 0);
	SegTree<Node1, Update1> sg = SegTree<Node1, Update1>(n, v);
	for(ll i = 0; i < m; i++){
		ll t, a, c;
		cin >> t;
		if(t == 1){
			cin >> a >> c;
			sg.make_update(a, c);
		}
		else{
			cin >> a >> c;
			cout << sg.make_query(a, c).val << '\n';
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
