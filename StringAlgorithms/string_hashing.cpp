#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define all(x) (x).begin(), (x).end()

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

// -------- Hashing ----------

const ll A = 911382323;
const ll B = 972663749;
vector<ll> h, p;

void prefixHash(vector<ll> nums)
{
    ll n = nums.size();
    h.assign(n, 0);
    p.assign(n, 0);
    h[0] = nums[0];
    p[0] = 1;
    for (int i = 1; i < n; i++)
    {
        h[i] = (h[i - 1] * A + nums[i]) % B;
    }
    for (int i = 1; i < n; i++)
    {
        p[i] = (p[i - 1] * A) % B;
    }
}

ll hash_(ll i, ll j)
{
    if (i != 0)
        return ((h[j] - h[i - 1] * p[j - i + 1]) % B + B) % B;
    return (h[j] + B) % B;
}

void solve()
{
    vector<ll> v = {1, 1, 2, 4, 1, 1, 2, 5};
    prefixHash(v);
    cout << hash_(0, 2) << " " << hash_(4, 6) << " ";
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
