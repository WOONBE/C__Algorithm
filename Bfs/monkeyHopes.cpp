//
// Created by 김헌우 on 2023/07/04.
//이거 계속 값이 추가되서 리턴되는거 고쳐야함
#include "bits/stdc++.h"
using namespace std;

#define X first
#define Y second
int INF = 1e9 + 7;
int board[201][201];
int dist[31][201][201]; //3차원 배열이 핵심
queue<tuple<int,int,int>> q;

int h,w; //h 세로, w 가로
int dx1[8] = {2, 1, -1, -2, -2, -1, 1, 2}; //나이트 처럼 움직임
int dy1[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx2[4] = {1,0,-1,0}; //기존 bfs move
int dy2[4] = {0,1,0,-1};

bool out(int a, int b){ // Out Of Bounds인지 체크하는 함수
    return a < 0 or a >= h or b < 0 or b >= w;
}

void bfs(){
    q.push({0,0,0});
    dist[0][0][0] = 1;
    while(!q.empty()){
        int horse,x,y,k;
        tie(horse,x,y) = q.front();
        q.pop();
        if(horse < k){
            for(int dir=0; dir<8; dir++){
                int nx = x + dx1[dir];
                int ny = y + dy1[dir];
                if(out(nx, ny) || board[nx][ny]== 1 ||dist[horse][nx][ny] ) continue;
                dist[horse+1][nx][ny] = dist[horse][x][y] + 1;
                q.push({horse+1,nx,ny});
            }
        }
        for(int dir=0;dir<4;dir++){
            int nx = x + dx2[dir];
            int ny = y + dy2[dir];
            if(out(nx, ny) || board[nx][ny]== 1 ||dist[horse][nx][ny] ) continue;
            dist[horse][nx][ny] = dist[horse][x][y]+1;
            q.push({horse,nx,ny});
        }
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k,y,x;

    cin >> k;
    cin >> w >> h;

    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> board[i][j];

    bfs();

    int ans = 0x7f7f7f7f;
    for (int i = 0; i < k + 1; i++)
        if (dist[i][h - 1][w - 1])
            ans = min(ans, dist[i][h - 1][w - 1]);
    if (ans != 0x7f7f7f7f) cout << ans - 1; //시작점을 1로 설정
    else cout << -1;
    return 0;

}



