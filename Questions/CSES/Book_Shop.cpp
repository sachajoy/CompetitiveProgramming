#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int n, x;
vector<int> price(n), pages(n);
vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    price.assign(n,0);
    pages.assign(n,0);
    dp.assign(n+1, vector<int>(x+1,0));
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (i == 0 || j==0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = dp[i - 1][j];
            if (j >= price[i - 1])
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j - price[i - 1]] + pages[i - 1]);
            }
        }
    }
    cout << dp[n][x];
    return 0;
}