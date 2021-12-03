#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
vector<vi> adj;
vi vis;
map<int, int> par;
bool bfs()
{
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    par[1] = -1;
    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();
        if (vertex == n)
            return true;
        for (int newv : adj[vertex])
        {
            if (!vis[newv])
            {
                vis[newv] = 1;
                par[newv] = vertex;
                q.push(newv);
            }
        }
    }
    return 0;
}
void solve()
{
    cin >> n >> m;
    adj.assign(n + 1, vi());
    vis.assign(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int ans = bfs();
    if (ans != 0)
    {
        // cout << ans + 1 << endl;
        int p = par[n];
        vi res;
        res.pb(n);
        while (p != -1)
        {
            // cout << p << endl;
            res.pb(p);
            p = par[p];
        }
        cout << res.size() << endl;
        reverse(res.begin(), res.end());
        for (int r : res)
            cout << r << " ";
    }
    else
    {
        cout << "IMPOSSIBLE";
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