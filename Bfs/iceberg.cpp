//
// Created by 김헌우 on 2023/07/04.
//

#include "bits/stdc++.h"
using namespace std;

#define X first
#define Y second

int board[302][302];
bool vis[302][302];
int zero[302][302];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int n,m;
queue<pair<int,int>> q;

void bfs(int x, int y){
    int cnt=0; //근처의 0의 갯수

    q.push({x,y});
    while (!q.empty()){
        auto cur = q.front();q.pop();
        for(int dir=0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(vis[nx][ny] || board[nx][ny] == 0) continue;
            if(board[nx][ny] == 0) cnt ++;
            vis[nx][ny] = true;
            board[nx][ny] = (board[nx][ny] - cnt);
            if(board[nx][ny] <0) board[nx][ny] = 0;
            q.push({nx,ny});
        }

    }


}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }
    bfs(0,0);





}