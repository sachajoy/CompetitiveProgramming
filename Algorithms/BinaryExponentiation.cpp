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
ll BinaryExponentiationRecursive(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll res = BinaryExponentiationRecursive(a, b/2);
    if(b%2){
        return res * res * a;
    }
    return res * res;
}

ll BinaryExponentiation(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1){
            res *= a;
        }
        a = a * a;
        b = b >> 1;
    }
    return res;
}
void solve()
{

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