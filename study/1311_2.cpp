#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
int N;
int arr[21][21];
ll full;
ll dp[21][1<<20]; //i번 배정했을때의 선택한 일의 집합 j

ll dfs(int cur, int state){
    if(state == full){
        return 0;
    }

    if(dp[cur][state] != -1){
        return dp[cur][state];
    }
    dp[cur][state] = 1e9;
    for(int i=0; i<N; i++){
        if(state & (1<<i)) continue; //이미 방문시
        dp[cur][state] = min(dp[cur][state], dfs(cur+1,state | (1<<i)) + arr[cur][i]);
    }
    return dp[cur][state];
}
int main(){

    cin >> N;
    full = (1<<N) - 1;
    memset(dp,-1,sizeof(dp));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(0,0) << "\n";
}