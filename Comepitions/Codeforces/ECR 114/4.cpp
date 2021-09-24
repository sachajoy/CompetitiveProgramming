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
vec<vec<ll>> eq;
set<vec<ll>> ba;
vec<ll> res;
ll msum = 0;
void helper(int i, vec<ll> &ans, ll sum){
    if(i == n){
        if(ba.find(ans) == ba.end()){
            if(sum > msum){
                msum = sum;
                res = ans;
            }
        }
        return;
    }
    for(int j=eq[i].size() - 1; j>=0; j--){
        ans.push_back(j+1);
        helper(i+1, ans, sum+eq[i][j]);
        ans.pop_back();
    }
}
void solve()
{
    cin >> n;
    eq.assign(n, vec<ll>());
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        for(int j=0; j<c; j++){
            int x;
            cin >> x;
            eq[i].push_back(x);
        }
        sort(eq[i].begin(), eq[i].end());
    }
    cin >> m;
    for(int i=0; i<m; i++){
        vec<ll> temp(n);
        for(int j=0; j<n; j++){
            cin >> temp[j];
        }
        ba.insert(temp);
    }
    vec<ll> a;
    helper(0, a, 0);
    for(int i=0; i<n; i++){
        cout << res[i] << " ";
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