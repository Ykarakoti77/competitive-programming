#include<bits/stdc++.h>
using namespace std;
#define ll long long

// function to find nCr
ll C(ll n , ll k){
	if(k > n-k)
	k = n - k;
	
	ll ans = 1;
	for(ll i=1;i<=k;i++)
	ans *= (n - i + 1) , ans /= i;
	
	return ans;
}

void solve(){ 
   ll n, r;
   cin >> n>> r;
   // To find nCr
   ll ans = C(n, r);
   cout << ans;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
