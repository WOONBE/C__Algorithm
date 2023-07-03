//
// Created by 김헌우 on 2023/07/03.
//1012, 변수를 전역으로 안두는게 중요(런타임 오류남), 테스트 케이스가 여러개인게 관건
#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int board[51][51]; //1은 배추있는 곳
bool vis[51][51]; // 해당 칸을 방문했는지 여부를 저장
int n,m,k;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1}; // 상하좌우 네 방향을 의미

queue <pair<int, int >> q;

void bfs(int x, int y) {
    vis[x][y] = true;
    q.push({ x,y });
    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        cin >> m >> n >> k;
        int x,y;
        for (int i = 0; i < k; i++) { //입력부분이 좀 햇갈렸음
            cin >> x >> y;
            board[y][x] = 1;
        }

        int num = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) { // (i, j)를 시작점으로 하고 싶은 상황
                if (board[i][j] == 1 && !vis[i][j]) {//1인곳을 시작점 하고싶음, 이부분 처리 잘못해서 피곤해짐
                    bfs(i, j);
                    num++;
                }
            }
        }
        cout << num << "\n";

        for (int i = 0; i < n; i++) {
            fill(board[i], board[i] + m, 0);  //초기화 시키고 한번 더 실행
            fill(vis[i], vis[i] + m, false);
        }
    }return 0;


}

