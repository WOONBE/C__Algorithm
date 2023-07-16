//
// Created by 김헌우 on 2023/07/03.
//3차원 배열로 풀이?, 벽 부수는거랑 안부수는거 감안해서 풀이, 마지막에 불가능한 케이스는 -1 리턴추가
//기존 2차원이랑 거의 차이 없음 대신에 벽 부수는 케이스 감안, 못풀었음
#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

char board[1001][1001];
int dist[1001][1001][2]; //3차원 배열이 코드짜기 쉽다 + tuple 연습(토마토), [0]은 벽 안부숨,[1]은 벽부숨
int dx[4]={1,0,-1,0};
int dy[4] ={0,1,0,-1};


int n,m;

int bfs(){
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            dist[i][j][0] = dist[i][j][1] = -1; //거리 관련 bfs는 -1로 초기화하면 따로 vis 안만들어도 됨

    dist[0][0][0] = dist[0][0][1] = 1;//방문표시

    queue<tuple<int,int,int>> q;
    q.push({0,0,0});
    while (!q.empty()) {
        int x, y, broken;
        tie(x, y, broken) = q.front();
        if(x == n-1 && y == m-1) return dist[x][y][broken]; //(0,0)부터 시작이라 -1씩 해준다
        q.pop();
        int nxt = dist[x][y][broken] + 1;
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1) {
                dist[nx][ny][broken] = nxt;
                q.push({nx, ny, broken});
            }
            // (nx, ny)를 부수는 경우
            if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1) {
                dist[nx][ny][1] = nxt;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i =0; i<n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    cout << bfs();
    return 0;


}

