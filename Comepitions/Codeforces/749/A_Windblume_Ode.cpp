#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
vector<ll> prime(100005, 1);
void isPrime(){
    int n = prime.size();
    for(int i=2; i<n; i++){
        if(prime[i]){
            for(int j=i*2; j<n; j=j+i){
                prime[j] = 0;
            }
        }
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum%2 == 0 || prime[sum] == 0){
        cout << n << endl;
        for(int i=0; i<n; i++){
            cout << i+1 << " ";
        }
        cout << endl;
        return;
    }
    if(prime[sum] != 0){
        int idx;
        for(int i=0; i<n; i++){
            int val = sum - arr[i];
            if(prime[val] == 0){
                idx = i;
                break;
            }
        }
        cout << n-1 << endl;
        for(int i=0; i<n; i++){
            if(i != idx){
                cout << i+1 << " ";
            }
        }
        cout << endl;
        return;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    isPrime();
    while (t--)
    {
        solve();
    }
    return 0;
}