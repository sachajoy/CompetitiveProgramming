#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
void solve()
{
    ll n, m, k;
    cin >> n >> m >> k;
    k -= 2;

    if (m < n - 1)
        cout << "NO" << '\n';

    else if (m > n * (n - 1) / 2)
        cout << "NO" << '\n';

    else if (k <= -1)
        cout << "NO" << '\n';

    else if (k == 0)
    {

        if (n == 1)
            cout << "YES" << '\n';

        else
            cout << "NO" << '\n';
    }

    else if (k == 1)
    {
        if (m == n * (n - 1) / 2)
            cout << "YES" << '\n';

        else
            cout << "NO" << '\n';
    }

    else
        cout << "YES" << '\n';
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