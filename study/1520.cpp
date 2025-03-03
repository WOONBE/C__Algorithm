#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M;
int board[501][501];
int dp[501][501]; //x,y에 내리막길로만 가능 경로의 수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

//0,0에서 무조건 시작
int dfs(int x, int y){

    if (x == N - 1 && y == M - 1) return 1;


    if(dp[x][y] != -1){
        return dp[x][y];
    }

    dp[x][y] = 0;

    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if (board[nx][ny] >= board[x][y]) continue;

        dp[x][y] += dfs(nx, ny);
    }
    return dp[x][y];
}

int main(){
    First

    cin >> N >> M;

    memset(dp,-1,sizeof(dp));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    cout << dfs(0,0) << "\n";

}