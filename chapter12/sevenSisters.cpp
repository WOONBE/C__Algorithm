//
// Created by 김헌우 on 2023/07/08.
//
#include "bits/stdc++.h"
using namespace std;
#define X first;
#define Y second;
int n = 5;
int cnt; //cnt는 4명이상 카운트, team은 마지막에 리턴할 값
int team = 0;
char board[5][5];
bool vis[5][5];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(int x, int y){

    queue<pair<int,int>> Q;
    Q.push({x,y});
    for(int i=0; i<7; i++){
        cnt = 0;
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(vis[nx][ny] != 0) continue; //이미 방문한 노드
            if(board[nx][ny] == 'S') cnt ++;
            vis[nx][ny] = 1;
            Q.push({nx,ny});
        }
    }if(cnt >= 4) team++;
    return 0;

}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> board[i][j];

    bfs(0,0);

    cout << team;

}

