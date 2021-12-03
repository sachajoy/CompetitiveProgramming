#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    dp[0][0] = grid[0][0] == '.' ? 1 : 0;
    for(int i=1; i<n; i++){
        dp[i][0] = grid[i][0] == '.' ? dp[i-1][0] : 0;
    }
    for(int i=1; i<n; i++){
        dp[0][i] = grid[0][i] == '.' ? dp[0][i-1] : 0;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<n; j++){
            if(grid[i][j] == '.'){
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
            }
        }
    }
    cout << dp[n-1][n-1];
    return 0;
}