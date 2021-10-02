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
void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> a;
    vec<pii> b;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[x] = i;
    }
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        b.push_back({x, i});
    }
    int ans = INT_MAX;
    int m = b[n-1].second;
    sort(b.begin(), b.end());
    int j=0;    
    for(int i=n-1; i>=0; i--){
        m = min(m, b[i].second);
        b[i].second = m;
    }
    for(int i=0; i<n; i++){
        m = a[i*2 + 1] + b[i].second;
        // j++;
        ans = min(m, ans);
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