#include <bits/stdc++.h>

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x) (x).begin(), (x).end()

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key
vector<vector<ll>> c;
vector<ll> sz, ctr, v, ans;
ll sum = 0;

// contribution of each node
void dfs1(ll x) {
  sz[x] = 1;
  for (ll i = 0; i < 2; i++) {
    if (c[x][i]) {
      dfs1(c[x][i]);
      sz[x] += sz[c[x][i]];
    }
  }
  sum += (ctr[x] = (sz[c[x][0]] + 1ll) * 1ll * (sz[c[x][1]] + 1ll) * v[x]);
}

void dfs2(ll x, ll del) {
  ll cur = sum - del - ctr[x];

  vector<ll> left, right;
  vector<pair<ll, ll>> ele;
  ll p = c[x][0];
  while (p) {
    left.push_back(p);
    cur -= ctr[p];
    p = c[p][1];
  }
  p = c[x][1];
  while (p) {
    right.push_back(p);
    cur -= ctr[p];
    p = c[p][0];
  }

  ll l = 0, r = 0;
  // idea of merging the rest of nodes if a single node is deleted
  while (l < left.size() || r < right.size()) {
    if (r >= right.size() || (l < left.size() && v[left[l]] < v[right[r]])) {
      ele.push_back({left[l], 0});
      l++;
    } else {
      ele.push_back({right[r], 1});
      r++;
    }
  }
  ll sub_siz = 0;
  for (ll i = (ll)ele.size() - 1; i >= 0; i--) {
    ll a = ele[i].first, b = ele[i].second;
    cur += (sub_siz + 1) * (sz[c[a][b]] + 1) * v[a];
    sub_siz += sz[c[a][b]] + 1;
  }
  ans[x] = cur;
  for (ll i = 0; i < 2; i++) {
    if (c[x][i]) dfs2(c[x][i], del + (sz[c[x][1 - i]] + 1ll) * v[x]);
  }
}

void solve() {
  ll n;
  cin >> n;
  v.assign(n + 1, 0);
  sz.assign(n + 1, 0);
  ctr.assign(n + 1, 0);
  ans.assign(n + 1, 0);
  c.assign(n + 1, vector<ll>(2, 0ll));
  for (ll i = 1; i <= n; i++) cin >> v[i];
  vector<ll> st(n + 2, 0);
  ll top = 0;
  // create cartesian tree
  for (ll i = 1; i <= n; i++) {
    while (top && v[st[top]] > v[i]) top--;
    c[i][0] = c[st[top]][1];
    c[st[top]][1] = i;
    st[++top] = i;
  }
  sum = 0ll;
  dfs1(st[1]);
  dfs2(st[1], 0ll);
  for (ll i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}