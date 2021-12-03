#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int m = max(a, max(b, c));
    if(m == 0){
        cout << 1 << " " << 1 << " " << 1;
        cout << endl;
        return;
    }
    if (a != m)
        a = m - a + 1;
    else
        a = 0;
    if (b != m)
        b = m - b + 1;
    else
        b = 0;
    if (c != m)
        c = m - c + 1;
    else
        c = 0;
    cout << a << " " << b << " " << c << endl;
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