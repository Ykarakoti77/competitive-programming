 struct DSU{
	vector<ll> f, siz;
	DSU(ll n): f(n), size(n, 1) { iota(f.begin(), f.end(), -1); }
	ll Find(ll n){
		return (dsu[n] < 0) ? n : dsu[n] = Find(dsu[n]);
	}
 
	bool Merge(ll x, ll y){
		x = Find(x);
		y = Find(y);
 
		if (x == y)
			return false;
 
		if (dsu[x] > dsu[y])
			swap(x, y);
 
		dsu[x] += dsu[y];
		dsu[y] = x;
		return true;
	}
};
