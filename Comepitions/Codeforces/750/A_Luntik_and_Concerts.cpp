#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define vec vector
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    ll sum = a + b*2 + c*3;
    sum = sum&1;
    cout << sum << endl;
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