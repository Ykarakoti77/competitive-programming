// Simple Segment Tree code for better understanding
// use Generic SegTree it reduces a lot of effort

const ll N = 200005;
vector<ll> arr(N);
vector<ll> seg(4 * N, 0);

void build(ll node, ll st, ll en){
    if(st == en){
        seg[node] = arr[st];
        return;
    }
    ll mid = st + (en - st) / 2;
    build(2 * node, st, mid);
    build(2 * node + 1, mid + 1, en);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

void update(ll node, ll st, ll en, ll pos, ll val){
    if(st == en){
        seg[node] = arr[pos] = val;
        return;
    }
    int mid = st + (en - st) / 2;
    if(pos <= mid) update(2 * node, st, mid, pos, val);
    else update(2 * node + 1,mid + 1, en, pos, val);
    seg[node] = seg[2 * node] + seg[2 * node + 1];
}

ll query(ll node, ll st, ll en , ll l, ll r){
    if(st >= l && en <= r) return seg[node];
    if(en < l || st > r) return 0;

    ll mid = (st + en) / 2;
    ll ansleft = query(2 * node, st, mid, l, r);
    ll ansright = query(2 * node + 1, mid + 1, en, l , r);
    return ansright + ansleft;
}
