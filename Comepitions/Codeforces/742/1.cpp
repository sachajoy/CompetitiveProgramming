#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
int n;
void solve()
{
    cin >> n;
    string ans = "";
    for(int i=0; i<n; i++){
        char a;
        cin >> a;
        if(a == 'U'){
            ans += "D";
        }else if(a == 'D'){
            ans += "U";
        }else{
            ans += a;
        }
    }
    cout << ans << endl;
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