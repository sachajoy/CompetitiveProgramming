#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define int ll
int n, q;
vector<ll> arr, tree;
void build(int start, int end, int idx)
{
    if (start == end)
    {
        tree[idx] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build(start, mid, idx * 2);
    build(mid + 1, end, idx * 2 + 1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}
int query(int start, int end, int idx, int a, int b)
{
    // outside
    if (end < a || start > b)
    {
        return 0;
    }
    // inside
    if (start >= a && end <= b)
    {
        return tree[idx];
    }
    // partially
    int mid = start + (end - start) / 2;
    int out1 = query(start, mid, 2 * idx, a, b);
    int out2 = query(mid + 1, end, 2 * idx + 1, a, b);
    return out1 + out2;
}
void update(int start, int end, int val, int idx, int index){
    if(start == end){
        tree[idx] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if(mid >= index){
        update(start, mid, val, 2*idx, index);
    }else{
        update(mid+1, end, val, 2*idx + 1, index);
    }
    tree[idx] = tree[2*idx] + tree[2*idx + 1];
}
void solve()
{
    cin >> n >> q; 
    arr.assign(n, 0);
    tree.assign(4 * n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build(0, n-1, 1);
    for(int i=0; i<q; i++){
        int a, b, c;
        cin >> c >> a >> b;
        if(c == 1){
            update(0, n-1, b, 1, a-1);
            continue;
        }
        int ans = query(0, n-1, 1, a-1, b-1);
        cout << ans << endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}