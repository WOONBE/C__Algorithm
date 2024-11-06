#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M,wall;
string arr[1001];
int dp[1001][1001][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct State{
    int x;
    int y;
    int broke;
};

int bfs(){
    queue<State> q;
    q.push({0,0,0});
    dp[0][0][0] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.x;
        int y = cur.y;
        int broke = cur.broke;


        if(x == N-1 && y == M-1 && broke<=wall){
            return dp[x][y][broke];
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny =  y + dy[i];
            if(nx <0 || ny <0 || nx>=N || ny>=M) continue;
            //벽이 없는 위치를 뚫고 갈때
            if(arr[nx][ny] == '0' && dp[nx][ny][broke] == 0){
                dp[nx][ny][broke] = dp[x][y][broke] + 1;
                q.push({nx,ny,broke});
            }
            else if(arr[nx][ny] == '1' && broke<wall && dp[nx][ny][broke+1] == 0){
                dp[nx][ny][broke+1] = dp[x][y][broke] + 1;
                q.push({nx,ny,broke+1});
            }

        }


    }
    return -1;

}
int main(){
    First

    cin >> N >> M >> wall ;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    cout << bfs() << "\n";
    return 0;


}