//
// Created by 김헌우 on 2023/06/29.
//메모리 초과떴음, board를 1차원 배열로 받으려다 런타임 오류(colordisable에 해답 있음)
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
string board[101];
int dist1[101][101]; //색약인 방문여부
int dist2[101][101]; //정상인 방문여부

int n;
int cnt1,cnt2=0; //구역수(색약,정상)
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i=0; i<n; i++)
        cin >> board[i];

    queue<pair<int,int> > Q1;
    queue<pair<int,int> > Q2;

    for(int i = 0; i < n; i++){ //색약인 시작
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'R' || board[i][j] == 'G'){
                Q1.push({i,j});
                dist1[i][j] = 0; //방문여부 표시
            }
            else
                Q1.push({i,j});
                dist1[i][j] = 1;
        }
    }
    for(int i = 0; i < n; i++){ //정상인 시작
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'R'){
                Q1.push({i,j});
                dist2[i][j] = 0; //방문여부 표시
            }
            if(board[i][j] == 'G'){
                Q1.push({i,j});
                dist2[i][j] = 1;
            }
            else
                Q1.push({i,j});
                dist2[i][j] = 1;
        }
    }
    while(!Q1.empty()){
        auto cur = Q1.front(); Q1.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist1[nx][ny] != dist1[nx+1][ny+1])
                cnt1 ++;
            Q1.push({nx,ny});
        }
    }
    while(!Q2.empty()){
        auto cur = Q2.front(); Q2.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist2[nx][ny] != dist2[nx+1][ny+1])
                cnt2 ++;
            Q1.push({nx,ny});
        }
    }
    cout << cnt2 << cnt1;

    //bfs 돌림

}
