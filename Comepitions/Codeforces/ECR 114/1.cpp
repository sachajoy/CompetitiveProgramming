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
void helper(int n, string s, int open, int &i){
    if(i == 0){
        return;
    }
    if(n == 0){
        cout << s << endl;
        i-=1;
        return;
    }
    if(n == open){
        helper(n-1, s+")", open-1, i);
        return;

    }
    helper(n-1, s+"(", open+1, i);
    helper(n-1, s+")", open-1, i);
}
void solve()
{
    cin >> n;
    int i = 2*n;
    helper(i-1, "(", 1, n);
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