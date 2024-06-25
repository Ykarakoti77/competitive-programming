// https://codeforces.com/contest/1986/problem/F
// https://cp-algorithms.com/graph/bridge-searching.html

#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x) (x).begin(), (x).end()

template <class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

ll n;
ll ans, tot;
vector<vector<ll>> adj;
vector<ll> vis;
vector<ll> tin, low, wt;
ll timer;

void IS_BRIDGE(ll v, ll to)
{ // perform operation on bridge vertex
    ans = max(ans, (n - wt[to]) * wt[to]);
}

void dfs(ll v, ll p = -1)
{
    vis[v] = true;
    tin[v] = low[v] = timer++;
    bool parent_skipped = false;

    for (auto &to : adj[v])
    {
        if (to == p && parent_skipped == false)
        {
            parent_skipped = true;
            continue;
        }
        if (vis[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(to, v);
            wt[v] += wt[to];
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                IS_BRIDGE(v, to);
            }
        }
    }
}

void find_bridges()
{
    timer = 0;
    vis.assign(n, false);
    wt.assign(n, 1ll);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
            tot += wt[i] * (wt[i] - 1) / 2;
        }
    }
}

void solve()
{
    ll m;
    cin >> n >> m;
    ans = 0, tot = 0;
    adj.assign(n, vector<ll>());
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    find_bridges();
    cout << tot - ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}