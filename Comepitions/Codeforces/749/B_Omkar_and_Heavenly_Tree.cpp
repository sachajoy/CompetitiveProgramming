#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n;
vector<vector<ll>> adj;
vector<ll> visited;
void dfs(int start){
    visited[start] = 1;
    for(auto vertex:adj[start]){
        if(!visited[vertex]){
            dfs(vertex);
        }
    }
}
void solve()
{
    cin >> n;
    set<int> res;
    int m;
    cin >> m;
    for(int i=0; i<m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        res.insert(b);
    }
    for(int i=1; i<=n; i++){
        if(res.find(i) == res.end()){
            m = i;
            break;
        }
    }
    for(int i=1; i<=n; i++){
        if(m != i){
            cout << m << " " << i << endl;
        }
    }
    
}
int main()
{
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