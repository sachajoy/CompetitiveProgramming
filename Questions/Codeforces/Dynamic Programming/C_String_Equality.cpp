#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define vec vector
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, k;
string a, b;
void solve()
{
    cin >> n >> k;
    cin >> a >> b;
    vector<int>have(27,0), need(27,0);
    for(auto s:a){
        have[s-'a']++;
    }
    for(auto s:b){
        need[s-'a']++;
    }
    bool flag = true;
    for(int i=0; i<26; i++){
        if(have[i] < need[i]){
            flag=false;
            break;
        }
        have[i] -= need[i];
        if(have[i]%k){
            flag=false;
            break;
        }
        have[i+1] += have[i];
    }
    if(flag) {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
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