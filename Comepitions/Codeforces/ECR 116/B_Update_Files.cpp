#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll k;
        cin >> k;
        if (n > k && k != 1)
        {
            ll sum = (k * (k + 1)) / 2;
            n -= sum;
            ll ans = k + ceil(n/k);
            cout << ans+1 << endl;
        }else if (k == 1){
            cout << n - 1 << endl;
        }else{
            ll ans = min(n, k)/2;
            cout << ans << endl;
        }
    }
    return 0;
}