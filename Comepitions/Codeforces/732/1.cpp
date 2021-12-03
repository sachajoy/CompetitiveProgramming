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
#define f first
#define s second
#define pb push_back
vi a, b;
vec<pii> m;
int n;
int findi()
{
    // int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            return i;
        }
    }
    return -1;
}
int findj()
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            return i;
        }
    }
    return -1;
}
void solve()
{
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    m.clear();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < 100; i++)
    {
        int ai = findi();
        int aj = findj();
        if (ai == -1 || aj == -1)
        {
            break;
        }
        a[ai] -= 1;
        a[aj] += 1;
        m.push_back({ai+1, aj+1});
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "-1" << endl;
            return;
        }
        
    }
    cout << m.size() << endl;
    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i].f << " " << m[i].s << endl;
    }
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