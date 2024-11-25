#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 987654321;

int N;
int full;
int arr[20][20];
int dp[20][1<<20];

int dfs(int cur, int state){


//    if(state == full){
//        return 0;
//    }
    if(cur >= N){
        return 0;
    }

    if(dp[cur][state] != -1) return dp[cur][state];
    dp[cur][state] = INF;

    for(int i=0; i<N; i++){
        if(state & (1<<i)) continue;
//        if(!arr[cur][i]) continue;
        dp[cur][state] = min(dp[cur][state], dfs(cur+1,state | (1<<i)) + arr[cur][i]);
    }

    return dp[cur][state];

}
int main(){
    First


    cin >> N;
    full = (1<<N) - 1;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));

    cout << dfs(0,0) << "\n";


}