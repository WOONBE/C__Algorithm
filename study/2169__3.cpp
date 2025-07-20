#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int arr[1001][1001];
int dp[1001][1001][3]; //x,y,들어온 방향에 따라 가질 수 있는 최대값
int dx[3] = {1,0,0}; //하,우,좌
int dy[4] = {0,1,-1};
int N,M;
bool OOB(int x, int y){
    return x>=0 && y>=0 && N>x && M >y;
}

int dfs(int x, int y, int dir){
    if(x == N-1 && y == M-1){
        return arr[x][y];
    }

    if(dp[x][y][dir] != -1) return dp[x][y][dir];

    dp[x][y][dir] = -1e9;

    for(int i=0; i<3; i++){
        if((dir==2 && i==1) || (dir==1 && i==2)) continue;
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!OOB(nx,ny)) continue;
        dp[x][y][dir] = max(dp[x][y][dir], dfs(nx,ny,i) + arr[x][y]);
    }
    return dp[x][y][dir];
}

int main(){
    First

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));

    cout << dfs(0,0,0) << "\n";

}