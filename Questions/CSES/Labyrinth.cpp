#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
vector<vector<char>> lab;
vector<vi> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
string mo = "LRDU";
map<pair<int, int>, int> parent;
bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
bool bfs(int i, int j, int ei, int ej)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = 1;
    parent[{i, j}] = -1;
    while (!q.empty())
    {
        auto cor = q.front();
        q.pop();
        if (cor.first == ei && cor.second == ej)
        {
            return true;
        }
        for (int k = 0; k < 4; k++)
        {
            int x = cor.first + dx[k];
            int y = cor.second + dy[k];
            if (valid(x, y) && !visited[x][y] && lab[x][y] != '#')
            {
                // char c = mo[k];
                parent[{x, y}] = k;
                visited[x][y] = 1;
                q.push({x, y});
            }
        }
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    lab.clear();
    lab.assign(n, vector<char>(m));
    visited.clear();
    visited.assign(n, vi(m, 0));
    parent.clear();
    int x = -1, y = -1;
    int ex = -1, ey = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> lab[i][j];
            if (lab[i][j] == 'A')
                x = i, y = j;
            if (lab[i][j] == 'B')
                ex = i, ey = j;
        }
    }
    bool f = bfs(x, y, ex, ey);
    if (f)
    {
        cout << "YES" << endl;
        string ans = "";
        int cor;
        cor = parent[{ex, ey}];
        // ans += mo[cor];
        // cout << ex << " - " << x << endl;
        // cout << ey << " - " << y << endl;
        bool flag = ex != x && ey != y;
        // cout << flag << endl;
        while (cor != -1)
        {
            ans += mo[cor];
            ex = ex - dx[cor];
            ey = ey - dy[cor];
            cor = parent[{ex, ey}];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    //     solve();
    // }
    solve();
    return 0;
}