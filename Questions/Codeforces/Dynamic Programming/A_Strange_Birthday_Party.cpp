#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define vec vector
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
void solve()
{
    cin >> n >> m;
    vi k(n), c(m);
    for (int i = 0; i < n; i++)
    {
        cin >> k[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> c[i];
    }
    sort(k.begin(), k.end());
    reverse(k.begin(), k.end());

    ll total = 0, j = 0;
    for (int i = 0; i < n; i++)
    {
        if (j < m)
        {
            if (c[j] < c[k[i] - 1])
            {
                total += c[j];
                j++;
            }
            else
            {
                total += c[k[i] - 1];
            }
        }
        else
        
        {
            total += c[k[i] - 1];
        }
    }
    cout << total << endl;
}
int main()
{
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