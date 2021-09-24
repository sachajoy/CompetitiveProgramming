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
int n, m;
ll x, y;
vector<ll> arr; 
ll sum;
ll ans;
int search(){
    int h=n-1, l=0;
    while(h >= l){
        int mid = l + (h - l) / 2;
        if(arr[mid] >= x){
            h = mid-1;
        }else{
            l = mid+1;
        }
    }
    return l;
}
void solve()
{
    sum = 0;
    cin >> n;
    arr.assign(n, 0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++) sum += arr[i];
    cin >> m; 
    for(int i=0; i<m; i++){
        ans = 2e18;

        cin >> x >> y;
        int index = search();
        // cout << x << " - " << y << " - " << index << endl;
        if(index > 0) 
            ans = min(ans, x - arr[index-1] + max(0LL, y - sum + arr[index-1]));
        if(index < n) 
            ans = min(ans, max(0LL, y-sum+arr[index]));
        cout << ans << endl;
    }


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
    // ll t;
    // cin >> t;
    // while (t--)
    // {
        solve();
    // }
    return 0;
}