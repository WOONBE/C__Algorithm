#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M;
int board[51][51];
bool visited[51][51] = {false,};
int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int bfs(int x, int y){
    int room_sze = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    visited[x][y] = true;
    room_sze++;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        x = cur.first;
        y = cur.second;

        int wall = 1;
        for(int dir=0; dir<4; dir++){
            if((board[x][y] & wall) != wall){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx>=0 && ny>=0 && nx<N && ny<M && visited[nx][ny] == false){
                    room_sze++;
                    visited[nx][ny] = true;
                    q.push({nx,ny});
                }
            }
            wall *= 2;
        }
    }
    return room_sze;
}
int main(){
    First

    cin >> M >> N;
    //이거 반대로 받는건데 그냥 그대로 받았다가 헤맴

    int room_cnt = 0;
    int mx_room_sze = 0;
    int mx_erase_room_sze = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(visited[i][j] == false){
                mx_room_sze = max(mx_room_sze,bfs(i,j));
                room_cnt ++;

            }
        }
    }

    cout << room_cnt << "\n";
    cout << mx_room_sze << "\n";


    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int wall = 1; wall<=8; wall*=2) {
                if ((board[i][j] & wall)== wall) {
                    memset(visited, false, sizeof(visited));
                    board[i][j] -= wall;
                    mx_erase_room_sze = max(mx_erase_room_sze, bfs(i, j));
                    board[i][j] += wall;
                }
            }
        }
    }


    cout << mx_erase_room_sze << "\n";
}