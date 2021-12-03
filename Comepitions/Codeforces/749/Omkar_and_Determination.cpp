#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
vector<vector<char>> grid;
void solve()
{
    cin >> n >> m;
    grid.assign(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<int> sum(m, 0);
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(grid[j-1][i] == 'X' && grid[j][i-1] == 'X'){
                sum[i]++;
            }
        }
    }
    for(int i=1; i<m; i++){
        sum[i] += sum[i-1];
    }
    int q;
    cin >> q;
    for(int i=0; i<q; i++){
        int x, y;
        cin >> x >> y;
        int val = sum[y-1] - sum[x-1];
        if(val == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}