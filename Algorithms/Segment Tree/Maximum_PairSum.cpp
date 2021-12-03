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
vector<pii> tree;
void build(int start, int end, int idx){
    if(start == end){
        tree[idx] = {arr[start], INT_MIN};
        return;
    }
    int mid = start + (end - start) / 2;
    build(start, mid, 2*idx);
    build(mid+1, end, 2*idx+1);
    pii x = tree[idx*2];
    pii y = tree[idx*2 + 1];
    tree[idx].first = max(x.first, y.first);
    tree[idx].second = min(max(x.first, y.second), max(x.second, y.first));
}

void update(int start, int end, int idx, int index, int value){
    if(start == end){
        tree[idx] = {value, INT_MIN};
        return;
    }
    int mid = start + (end - start) / 2;
    if(index <= mid){
        update(start, mid, 2*idx, index, value);
    }else{
        update(mid+1, end, 2*idx + 1, index, value);
    }
    pii x = tree[idx*2];
    pii y = tree[idx*2 + 1];
    tree[idx].first = max(x.first, y.first);
    tree[idx].second = min(max(x.first, y.second), max(x.second, y.first));
}
pii query(int start, int end, int l, int r, int idx){
    if(end < l || start > r){
        return {INT_MIN, INT_MIN};
    }
    if(start >= l && end <= r){
        return tree[idx];
    }
    int mid = start + (end - start) / 2;
    pii x = query(start, mid, l, r, 2*idx);
    pii y = query(mid+1, end, l, r, 2*idx + 1);
    pii res;
    res.first = max(x.first, y.first);
    res.second = min(max(x.first, y.second), max(x.second, y.first));
    return res;
}
void solve()
{
    cin >> n;
    arr.assign(n, 0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    tree.assign(4*n, pii());
    
    build(0, n-1, 1);
    cin >> q;
    for(int i=0; i<q; i++){
        char c;
        int a, b;
        cin >> c;
        cin >> a >> b;
        if(c == 'Q'){
            // cout << c << endl;
            pii res = query(0, n-1, a-1, b-1, 1);
            cout << res.first + res.second << endl;;
        }else{
            update(0, n-1, 1, a-1, b);
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