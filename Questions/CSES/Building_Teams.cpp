#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, m;
vector<vector<int>> adj;
vector<int> vis, col;
bool dfs(int s, int c){
    vis[s] = 1;
    col[s] = c;
    for(auto v:adj[s]){
        if(!vis[v]){
            bool f = dfs(v, c^1);
            if(!f) return false;
        }else if(col[s] == col[v]){
            return false;
        }
    }
    return true;
}
void solve()
{
    cin >> n >> m;
    adj.assign(n, vector<int>());
    vis.assign(n, 0);
    col.assign(n, -1);
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    bool ans = true;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            ans &= dfs(i, 0);
        }
    }
    if(ans){
        for(auto c:col){
            cout << c+1 << " ";
        }
    }else{
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