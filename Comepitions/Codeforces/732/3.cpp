#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
vi a;
// vec<bool> dir;
vec<vi> cnt(100001, vi(2, 0));
int n;
void solve()
{
    cin >> n;
    a.assign(n, 0);
    // cnt.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]][i % 2]++;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        cnt[a[i]][i % 2]--;
    }
    for (int i = 0; i < n; i++)
    {
        if (cnt[a[i]][0] != 0 || cnt[a[i]][1] != 0)
        {
            cout << "NO" << endl;
            for (int i = 0; i < n; ++i)
                cnt[a[i]][0] = cnt[a[i]][1] = 0;
            return;
        }
    }
    for (int i = 0; i < n; ++i)
        cnt[a[i]][0] = cnt[a[i]][1] = 0;
    cout << "YES" << endl;
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