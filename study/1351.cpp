#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
ll N,P,Q;
map<ll,ll> dp;
ll dfs(ll n){
    if(dp.count(n)){
        return dp[n];
    }
    if(n==0){
        return dp[n] = 1;
    }

    return dp[n] = dfs(n/P) + dfs(n/Q);
}
int main(){
    First
    cin >> N >> P >> Q;
    dp[0] = 1;
    cout << dfs(N) << "\n";
}