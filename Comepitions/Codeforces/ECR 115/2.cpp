#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n;
vector<vector<int>> stu;

bool helper(int d1, int d2, int t1, int t2, int st)
{
    if (st < 0)
    {
        if (t1 == t2)
        {
            return true;
        }
        return false;
    }
    if (stu[st][d1] == 0 && stu[st][d2] == 0)
    {
        return false;
    }
    if (stu[st][d1] == 1 && stu[st][d2])
    {
        bool out1 = helper(d1, d2, t1 + 1, t2, st - 1);
        bool out2 = helper(d1, d2, t1, t2 + 1, st - 1);
        return out1 || out2;
    }
    if (stu[st][d1] == 1)
    {
        return helper(d1, d2, t1 + 1, t2, st - 1);
    }
    return helper(d1, d2, t1, t2 + 1, st - 1);
}
void solve()
{
    cin >> n;
    stu.clear();
    stu.assign(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> stu[i][j];
        }
    }
    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            int c1=0, c2=0, both=0;
            for(int k=0; k<n; k++){
                if(stu[k][i] && stu[k][j]) both++;
                else if(stu[k][i]) c1++;
                else if(stu[k][j])c2++;
            }
            if(both+c1+c2 == n){
                if(c1>c2){
                    swap(c2, c1);
                }
                if(both >= c2-c1){
                    both = both-c2-c1;
                    if(both%2 == 0){
                        cout << "YES" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
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