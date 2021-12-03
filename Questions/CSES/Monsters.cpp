#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define vec vector
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
vec<vec<char>> grid;
vec<vec<int>> timet, par;
vec<vec<int>> vis;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
string s = "LRDU";
queue<pii> moster, q;
pii st, ed;
bool isValid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m;
}
bool canExit(int x, int y)
{
    return x == 0 || y == 0 || x == n - 1 || y == m - 1;
}
void bfs_monster()
{
    int t = 1;
    while (!moster.empty())
    {
        int size = moster.size();
        while (size--)
        {
            pii cor = moster.front();
            moster.pop();
            int x = cor.first;
            int y = cor.second;
            timet[x][y] = t;
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (isValid(newx, newy) && grid[newx][newy] != '#' && !vis[newx][newy])
                {
                    vis[newx][newy] = 1;
                    moster.push({newx, newy});
                    par[newx][newy] = i;
                }
            }
        }
        t++;
    }
}
bool bfs_path()
{
    int t = 1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pii cor = q.front();
            q.pop();
            int x = cor.first;
            int y = cor.second;
            if (canExit(x, y))
            {
                ed = {x, y};
                return true;
            }
            for (int i = 0; i < 4; i++)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if (isValid(newx, newy) && grid[newx][newy] != '#' && !vis[newx][newy])
                {
                    if (t < timet[newx][newy])
                    {
                        vis[newx][newy] = 1;
                        q.push({newx, newy});
                    }
                }
            }
        }
        t++;
    }
    return false;
}
void solve()
{
    cin >> n >> m;
    grid.assign(n, vec<char>(m));
    vis.assign(n, vec<int>(m, 0));
    timet.assign(n, vec<int>(m, 0));
    par.assign(n, vec<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'M')
            {
                moster.push({i, j});
                vis[i][j] = 1;
            }
            if (grid[i][j] == 'A')
            {
                st = {i, j};
                q.push({i, j});
            }
        }
    }
    bfs_monster();
    vis.clear();
    vis.assign(n, vec<int>(m, 0));
    int ans = bfs_path();
    if (!ans)
    {
        cout << "NO";
        return;
    }
    cout << "YES" << endl;
    string r = "";
    int i = par[ed.first][ed.second];
    r += s[i];
    while (ed != st)
    {
        int x = ed.first - dx[i];
        int y = ed.second - dy[i];
        ed = {x, y};
        i = par[x][y];
        r += s[i];
    }
    cout << r;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}