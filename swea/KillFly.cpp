//
// Created by 김헌우 on 2023/12/28.
//12712
// 보류

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int T,N,M;


int board[16][16];
bool vis1[16][16];
bool vis2[16][16];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dxc[4] = {-1, 1, -1, 1};
int dyc[4] = {-1, 1, 1, -1};

#define X first
#define Y second

queue<pair<int,int>> Q;

int bfs1(int x,int y){
    int sum = 0;
    vis1[0][0] = 1; // (0, 0)을 방문했다고 명시
    Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dx[dir] * M;
            int ny = cur.Y + dy[dir] * M; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 밖일 경우 넘어감
            if(vis1[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis1[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            sum += board[nx][ny];
            Q.push({nx,ny});
        }
    }return sum;
}
int bfs2(int x,int y){
    int sum = 0;
    vis2[0][0] = 1; // (0, 0)을 방문했다고 명시
    Q.push({0,0}); // 큐에 시작점인 (0, 0)을 삽입.
    while(!Q.empty()){
        pair<int,int> cur = Q.front(); Q.pop();

        for(int dir = 0; dir < 4; dir++){ // 상하좌우 칸을 살펴볼 것이다.
            int nx = cur.X + dxc[dir] * M;
            int ny = cur.Y + dyc[dir] * M; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue; // 범위 밖일 경우 넘어감
            if(vis2[nx][ny] || board[nx][ny] != 1) continue; // 이미 방문한 칸이거나 파란 칸이 아닐 경우
            vis2[nx][ny] = 1; // (nx, ny)를 방문했다고 명시
            sum += board[nx][ny];
            Q.push({nx,ny});
        }
    }return sum;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for(int t=0; t<T; t++){
        cin >> N >> M;

        while (!Q.empty()) {
            Q.pop(); // 각 테스트 케이스마다 Q를 초기화
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> board[i][j];
            }
        }
        int result = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) { // (i, j)를 시작점으로 하고 싶은 상황
                    int value1 = bfs1(i,j);
                    int value2 = bfs2(i,j);
                    result = max(value1,value2);
                }
            }

        cout<< "#" << t + 1  <<  " " <<  result << '\n';
    }

}
