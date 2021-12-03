#include <bits/stdc++.h>
using namespace std;
#define mod int(1e9 + 7)
#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define mp make_pair
#define pb push_back
int n, q;
vi arr;
vi tree;
void build(int start, int end, int idx){
    // cout << start << " - " << end << endl;
    if(start == end){
        tree[idx] = arr[start];
        return;
    }
    int mid = start + (end - start) / 2;
    build(start, mid, idx*2);
    build(mid+1, end, idx*2 + 1);
    tree[idx] = min(tree[2*idx], tree[idx*2 + 1]);
}
void update(int start, int end, int val, int i, int idx){
    // cout << start << " - " << end << endl;
    if(start == end){
        tree[idx] = val;
        arr[i] = val;
        return;
    }
    int mid = start + (end - start) / 2;
    if(mid >= i){
        update(start, mid, val, i, 2*idx);
    }else{
        update(mid+1, end, val, i, 2*idx+1);
    }
    tree[idx] = min(tree[2*idx], tree[2*idx + 1]);
}
int query(int start, int end, int l, int r, int idx){
    // cout << start << " - " << end << endl;
    if(start >= l && end <= r){
        return tree[idx];
    }
    if(start > r || end < l){
        return INT_MAX;
    }
    int mid = start + (end - start) / 2;
    int out1 = query(start, mid, l, r, 2*idx);
    int out2 = query(mid+1, end, l, r, 2*idx+1);
    return min(out1, out2);
}
void solve()
{
    cin >> n;
     cin >> q;
    arr.assign(n, 0);
    tree.assign(4*n, 0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    build(0, n-1, 1);
    for(int i=0; i<q; i++){
        char c;
        int l, r;
        cin >> c;
        cin >> l >> r;
        if(c == 'q'){
            cout << query(0, n-1, l-1, r-1, 1) << endl;
        }else{
            update(0, n-1, r, l-1, 1);
        }
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