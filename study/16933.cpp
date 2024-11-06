#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
int N,M,wall;
string arr[1001];
int dp[1001][1001][10][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct State{
    int x;
    int y;
    int broke;
    int turn;
};
int bfs(){
    queue<State> q;
    q.push({0,0,0,0});
    dp[0][0][0][0] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.x;
        int y = cur.y;
        int broke = cur.broke;
        int turn = cur.turn;

        if(x == N-1 && y == M-1 && broke<=wall){
            return dp[x][y][broke][turn];
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nxt_turn = 1-turn;
            if(nx < 0 || ny <0 || nx>=N || ny >=M) continue;
            //벽 없는 곳 이동시
            if(arr[nx][ny] == '0' && dp[nx][ny][broke][nxt_turn] == 0){
                dp[nx][ny][broke][nxt_turn] = dp[x][y][broke][turn] + 1;
                q.push({nx,ny,broke,nxt_turn});
            }
            //벽 부수고 이동시, 낮 밤여부 확인
            else if(arr[nx][ny] == '1' && broke<wall && dp[nx][ny][broke+1][nxt_turn] == 0 && turn  == 0){
                dp[nx][ny][broke+1][nxt_turn] = dp[x][y][broke][turn] + 1;
                q.push({nx,ny,broke+1,nxt_turn});
            }
//            //벽 있는데 못부수는 경우
//            else if(arr[nx][ny] == '1' && broke<wall && dp[nx][ny][broke+1] == 0 && turn %2 ==1){
//                q.push({x,y,broke,turn+1});
//            }
        }
        //밤이라 이동 못하는 경우
        if(dp[x][y][broke][1-turn] == 0){
            dp[x][y][broke][1-turn] = dp[x][y][broke][turn] + 1;
            q.push({x,y,broke,1-turn});

        }
    }
    return -1;
}
int main(){
    First

    cin >> N >> M >> wall;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    cout << bfs() << "\n";
    return 0;

}