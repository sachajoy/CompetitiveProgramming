#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        ll ans = INT_MAX;
        for(int i=0; i<26; i++){
            char a = 'a' + i;
            int l=0, r=n-1;
            ll count=0;
            bool can=true;
            while(l < r){
                if(s[l] == s[r]){
                    l++; r--;
                }else if(s[l] == a){
                    l++;
                    count++;
                }else if(s[r] == a){
                    r--;
                    count++;
                }else{
                    can = false;
                    break;
                }
            }
            if(can){
                ans = min(ans, count);
            }
        }
        if(ans != INT_MAX){
            cout << ans << endl;
        }else{
            cout << -1 << endl;
        }
    }
    return 0;
}