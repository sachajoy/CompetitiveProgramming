#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
vector<vector<int>> adj;
vi vis;
void dfs(int start, vector<int> &comp)
{
    vis[start] = 1;
    comp.pb(start);
    for (auto vertex : adj[start])
    {
        if (!vis[vertex])
        {
            dfs(vertex, comp);
        }
    }
}
void solve()
{
    cin >> n >> m;
    adj.assign(n+1, vector<int>());
    vis.assign(n, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].pb(b - 1);
        adj[b - 1].pb(a - 1);
    }
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            vector<int> ans;
            dfs(i, ans);
            res.pb(ans);
        }
    }
    if(res.size() == 1){
        cout << 0 << endl;
        return;
    }
    cout << res.size() - 1 << endl;
    for(int i=1; i<res.size(); i++){
        cout << res[0][0]+1 << " " << res[i][0]+1 << endl;
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