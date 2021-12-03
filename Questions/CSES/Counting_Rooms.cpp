#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
vector<vector<char>> building;
vector<vi> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}
void dfs(int i, int j)
{
    visited[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid(x, y) && !visited[x][y] && building[x][y] == '.')
        {
            dfs(x, y);
        }
    }
}
void solve()
{
    cin >> n >> m;
    building.clear();
    building.assign(n, vector<char>(m));
    visited.clear();
    visited.assign(n, vi(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> building[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && building[i][j] == '.')
            {
                // cout << i << " - " << j << endl;
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}