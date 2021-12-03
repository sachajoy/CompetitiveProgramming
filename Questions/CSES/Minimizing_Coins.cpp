#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, x;
vi coins;
vector<int> dp;
void solve()
{
    cin >> n >> x;
    coins.assign(n, 0);
    dp.assign(x + 1, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    dp[0] = 0;
    for (int j = 1; j <= x; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j >= coins[i])
            {
                int ans = dp[j - coins[i]];
                if (ans != INT_MAX && ans + 1 < dp[j])
                {
                    dp[j] = ans + 1;
                }
            }
        }
    }
    // cout << minCoins(n, x) << endl;

    if (dp[x] == INT_MAX){
        cout << -1;
        return;
    }
    cout << dp[x];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}