#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

vector<vector<int>> adj;
vector<int> vis, ans, par;
int n, m, start, e;
bool dfs(int s, int p)
{
    vis[s] = 1;
    // par[s] = p;
    for (auto v : adj[s])
    {

        if (!vis[v])
        {
            par[v] = s;
            if (dfs(v, par[v]))
            {
                return true;
            }
        }
        else if (v != p)
        {

            start = v;
            e = s;
            return true;
        }
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    adj.assign(n, vector<int>());
    vis.assign(n, 0);
    par.assign(n, -1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }
    start = -1;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] && dfs(i, par[i]))
        {
            break;
        }
    }
    if (start == -1)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        vector<int> cycle;
        cycle.push_back(start);
        int i = e;
        while (i != start)
        {
            cycle.push_back(i);
            i = par[i];
        }
        cycle.push_back(start);
        cout << cycle.size() << endl;
        for (auto i : cycle)
            cout << i + 1 << " ";
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