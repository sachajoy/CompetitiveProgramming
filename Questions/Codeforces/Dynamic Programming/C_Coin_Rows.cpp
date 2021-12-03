#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define vec vector
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int m;
vec<vec<ll>> arr;
void solve()
{
    cin >> m;
    arr.assign(2, vec<ll>(m));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    ll sum1=0, sum2=0, ans=INT_MAX;
    for(int i=0; i<m; i++){
        sum1 += arr[0][i];
    }
    for(int i=0; i<m; i++){
        sum1 -= arr[0][i];
        ans = min(ans, max(sum1, sum2));
        sum2 += arr[1][i];
    }
    cout << ans << endl;
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