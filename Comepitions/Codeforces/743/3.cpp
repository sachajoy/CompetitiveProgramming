#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
int n;
vector<vector<int>> edges;
vector<int> in;
vector<int> visited;
int ans = 0;
void bfs()
{
    queue<int> q;
    bool noans = true;
    for(int i=1; i<=n; i++){
        if(in[i] == 0){
            q.push(i);
            visited[i] = 1;
            noans = false;
        }
    }
    if(noans) {
        ans = -1;
        return;
    }
    vector<int> day(n+1, 1);
    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        // cout << vertex << endl;
        for(auto v : edges[vertex]){
            if(!visited[v]){
                // Increasing the day as if previous chapter was before of after
                if(v > vertex){
                    day[v] = max(day[v], day[vertex]);
                }else{
                    // If pre requsite was after then by +1 
                    day[v] = max(day[v], day[vertex]+1);
                }
                
                in[v]--;
                if(in[v] == 0){
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }
    ans = INT_MIN;
    for(int i=1; i<=n; i++){
        if(in[i] != 0){
            ans = -1;
            return;
        }
        ans = max(day[i], ans);
    }
}
void solve()
{
    cin >> n;
    ans = 0;
    edges = vvi(n+1);
    in.assign(n + 1, 0);
    visited.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        if(k == 0){
            in[i] = 0;
            continue;
        }
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            edges[a].push_back(i);
            in[i] += 1;
        }
    }
    bfs();
    cout << ans << endl;
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