#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
int dp[501][501]; //x,y일때 도달 가능한 경로의 수
int arr[501][501];
int M,N;

bool OOB(int x, int y){
    if(x <0 || y<0 || x>=M || y>=N) return true;
    else return false;
}
int bfs(int x, int y){
    if(dp[x][y] != -1) return dp[x][y];
    if(x == M-1 && y == N-1) return 1;

    dp[x][y] = 0;

    for(int dir=0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx,ny)) continue;
        if(arr[x][y] <= arr[nx][ny]) continue;
        dp[x][y] += bfs(nx,ny);
    }
    return dp[x][y];
}

int main(){
    First
    cin >> M >> N;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    cout << bfs(0,0) << "\n";


}