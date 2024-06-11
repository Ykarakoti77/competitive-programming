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

// Z algorithm is a linear time string matching algorithm which runs in O(n) complexity

vector<ll> z_function(string s)
{
    ll n = s.length();
    vector<ll> z(n);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            r = i + z[i];
            l = i;
        }
    }
    return z;
}

void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> na(n);
    na[n - 1] = s[n - 1] != 'a' ? (n - 1) : n;
    for (ll i = n - 2; i >= 0; i--)
    {
        na[i] = s[i] != 'a' ? i : na[i + 1];
    }
    if (na[0] == n)
    {
        cout << n - 1 << '\n';
        return;
    }
    string t = s.substr(na[0]);
    vector<ll> z = z_function(t);
    ll ans = 0;
    ll ni = t.length();
    for (ll len = 1; len <= ni; len++)
    {
        ll ca = na[0];
        ll ind = na[0] + len;
        while (ind < n && na[ind] < n && z[na[ind] - na[0]] >= len)
        {
            ca = min(ca, na[ind] - ind);
            ind = na[ind] + len;
        }
        if (na[ind] == n || ind == n)
        {
            ans += ca + 1;
        }
    }
    cout << ans << '\n';
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
