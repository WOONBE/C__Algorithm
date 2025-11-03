#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int arr[21][21];
int dp[21][1<<21];
int N;
int full;
#define INF 987654321
int dfs(int idx, int state){
    if(state == full){
        return 0;
    }
    if(dp[idx][state] != -1) return dp[idx][state];

    dp[idx][state] = INF;

    for(int i=0; i<N; i++){
        if(state & (1<<i)) continue;//&&로 잘못 사용
        dp[idx][state] = min(dp[idx][state], dfs(idx+1, state | (1<<i)) + arr[idx][i]); //i번 비트를 켜야함
    }

    return dp[idx][state];
}


int main(){
    First

    cin >> N;
    full = (1<<N) -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N;i++){
        for(int j=0; j<(1<<N);j++){
            dp[i][j] = -1;
        }
    }
    cout << dfs(0,0) << "\n";

}