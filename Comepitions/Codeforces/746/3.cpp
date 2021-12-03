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
string s;
int n;
char c;
void solve()
{
    cin >> n;
    cin >> c;
    cin >> s;
    int ixd = 0;
    bool f = false;
    int i;
    for(i=n-1; i>=0; i--){
        if(s[i] == c){
            ixd = max(i+1, ixd);
        }
        if(s[i] != c){
            f = true;
        }
    }
    if(!f){
        cout << 0 << endl;
        return;
    }
    if(ixd > n/2){
        cout << 1 << endl;
        cout << ixd << endl;
    }else{
        cout << 2 << endl;
        cout << n-1 << " " << n << endl;
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
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}