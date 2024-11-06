#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M;
string arr[1001]; //string으로 안받아도 동작을 안했음
int dp[1001][1001][2];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


struct State{
    int x,y,broken;
};
int bfs(){
    queue<State> q;
    q.push({0,0,0});
    dp[0][0][0] = 1;


    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.x;
        int y= cur.y;
        int broken = cur.broken;


        //도착했으면 해당 거리 리턴
        if(x == N-1 && y == M-1){
            return dp[x][y][broken];
        }

        for(int i=0; i<4; i++){
            int nx = x+ dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx>=N || ny>=M) continue;
            //벽이 없고 방문한 적 없을때
            if(arr[nx][ny] == '0' && dp[nx][ny][broken] == 0){
                dp[nx][ny][broken] = dp[x][y][broken] + 1;
                q.push({nx,ny,broken});
            }
            else if(arr[nx][ny] == '1' && dp[nx][ny][1] == 0 && broken == 0){
                dp[nx][ny][1] = dp[x][y][broken] + 1;
                q.push({nx,ny,1});
            }

        }
    }
    return -1;
}
int main(){
    First

    cin >> N >> M;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    cout << bfs() << "\n";
    return 0;
}