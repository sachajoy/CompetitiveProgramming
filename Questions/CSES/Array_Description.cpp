#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int n, m;
vector<int> arr;
vector<ll> dp;
int helper(int i)
{
    if (i == n)
    {
        return 1;
    }

    int ans = 0;
    if (i != 0 && arr[i] != 0 && abs(arr[i] - arr[i - 1]) > 1)
    {
        return 0;
    }
    // if (dp[i] != -1)
    //     return dp[i];
    if (arr[i] == 0)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 0)
            {
                // cout << j << " - " << i << endl;
                arr[i] = j;
                ans += helper(i + 1);
                arr[i] = 0;
            }
            else if (i == n - 1 && abs(arr[i - 1] - j) <= 1)
            {
                // cout << j << " - " << i << endl;
                arr[i] = j;
                ans += helper(i + 1);
                arr[i] = 0;
            }
            else if ((abs(arr[i - 1] - j) <= 1))
            {
                // cout << j << " - " << i << endl;
                arr[i] = j;
                ans += helper(i + 1);
                arr[i] = 0;
            }
        }
        return dp[i] = ans % mod;
    }
    return dp[i] = helper(i + 1);
}
void solve()
{
    cin >> n >> m;
    arr.assign(n, 0);
    dp.assign(n, -1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << helper(0) % mod;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}