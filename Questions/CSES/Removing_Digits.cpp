#include<bits/stdc++.h>
using namespace std;
vector<int> dp;
int helper(int n){
    // cout << n << endl;
    if(n == 0){
        return 0;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    int t=n;
    int v=INT_MAX;
    while(t!=0){
        int temp = t%10;
        t = t/10;
        if(temp != 0)
        v = min(v, helper(n-temp)+1);
    }
    return dp[n] = v;
}
int main(){
    int n;
    cin >> n;
    dp.assign(n+1, -1);
    cout << helper(n);
    return 0;
}