#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6; j++){
            if(i - j >= 0){
                dp[i] += dp[i - j];
                dp[i] = dp[i]%mod;
            }
        }
    }
    cout << dp[n]%mod << endl;
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
    solve();
    return 0;
}