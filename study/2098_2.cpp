#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
ll arr[16][16];
ll dp[16][1<<16];
int N;
ll full;

ll dfs(ll cur, ll state){
    if(state == full){
        if(arr[cur][0]){
            return arr[cur][0];
        }else{
            return 1e9;
        }
    }

    if(dp[cur][state] != -1){
        return dp[cur][state];
    }
    dp[cur][state] = 1e9;

    for(int i=0; i<N; i++){
        if(state & (1<<i)) continue;
        if(!arr[cur][i]) continue;
        dp[cur][state] = min(dp[cur][state], dfs(i,(state | (1<<i))) + arr[cur][i]);
    }
    return dp[cur][state];
}
int main(){
    First

    cin >> N;
    full = (1<<N) -1;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(0,1) << "\n";
}