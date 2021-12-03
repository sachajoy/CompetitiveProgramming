#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
void solve()
{
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    bool flag = true;
    for(int i=0; i<n; i++){
        if(s1[i] =='1' && s2[i] == '1'){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << "YES";
    }else{
        cout << "NO";
    }
    cout << endl;
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