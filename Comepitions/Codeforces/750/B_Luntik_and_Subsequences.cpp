#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define vec vector
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    int one=0, zero=0;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        sum += a;
        if(a == 1){
            one++;
        }
        if(a == 0){
            zero++;
        }
    }
    ll ans = 0;
    if(sum == 1){
        ans = pow(2, zero);
    }else if(sum > 1){
        ans = one;
        ans = ans * pow(2, zero);
    }
    cout << ans << endl;
}
int main()
{
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