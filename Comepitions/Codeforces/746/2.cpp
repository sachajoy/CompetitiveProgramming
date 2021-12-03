#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
void solve()
{
    ll n;
    cin >> n;
    ll k;
    cin >> k;
    ll ans = 0;
    ll mod = 1000000007;
    ll p = 1;
    for (ll i = 0; i < 32; i++)
    {
        if (k & (1 << i))
        {
            ans = (ans + p)%mod;
        }
        p = p * n;
        p = p%mod;
    }
    cout << ans % mod << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}