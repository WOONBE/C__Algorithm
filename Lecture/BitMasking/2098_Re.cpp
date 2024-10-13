#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 987654321
int arr[16][16];
int dp[16][1<<16]; //지금 현재 위치,  방문한 위치들 저장
int full;


int n;

int dfs(int cur, int state){
    //기저 조건
    if(state == full){
        if(arr[cur][0])return arr[cur][0]; //이부분 실수
        else{
            return INF; //이부분 실수
        }
    }
    if(dp[cur][state] != -1){
        return dp[cur][state];
    }
    dp[cur][state] = INF;
    for(int i=0; i<n; i++){
        if(state & (1 << i)) continue; //이미 방문했으면
        if(!arr[cur][i]) continue; //가는 길이 없으면
        dp[cur][state] = min(dp[cur][state], dfs(i,state | (1 << i)) + arr[cur][i]);

    }

    return dp[cur][state];

}
int main(){

    First
    cin >> n;
    full = (1<<n) -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));

    cout << dfs(0,1) << "\n";
}
