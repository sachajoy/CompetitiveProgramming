#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
int n, m;
vector<vector<pair<int, int>>> adj;
vector<int> vis, dist;
void dijkstra(int s)
{
    dist[s] = 0;

    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && (v == -1 || dist[v] > dist[j]))
            {
                v = i;
            }
        }

        if (dist[v] == INT_MAX)
            break;

        for (auto p : adj[v])
        {
            int node = p.first;
            int val = p.second;
            if (dist[node] > dist[v] + val)
            {
                dist[node] = dist[v] + val;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << dist[i] << " ";
        // }
        // cout << endl;
    }
}
void solve()
{
    cin >> n >> m;
    adj.assign(n, vector<pair<int, int>>());
    vis.assign(n, 0);
    dist.assign(n, INT_MAX);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a - 1].push_back({b - 1, c});
        // adj[b - 1].push_back({a - 1, c});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
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