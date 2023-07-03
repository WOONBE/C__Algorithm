//
// Created by 김헌우 on 2023/07/03.
//함수로 빼서 구현
#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second //대문자 있으면 안됨, ;쓰면 안됨

int dist[301][301];
//bool vis[301][301]; //bool로 해줘야함(true or false 반환),이건 거리 구하는거라 vis 따로 필요 없긴함

int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1}; //방향 나누는거까진 성공적
int n,x,y,xx,yy; //얘네 계속 초기화 시킬거라 전역

queue<pair<int,int>> q;

void bfs(int x,int y){
    //vis[x][y] = true;
    cin >> xx >> yy ;
    q.push({x,y});
    while (!q.empty()){
        auto cur = q.front();q.pop();
        for(int dir=0; dir < 8; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>n) continue;
            if(dist[nx][ny] >=0) continue; //다 -1로 초기화 할거라 다른수면 vis=true랑 같음
            //vis[nx][ny] = true;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            q.push({nx,ny});
        }

    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--){
        cin >> n;
        for (int i = 0; i < n; i++) fill(dist[i], dist[i] + n, -1); //거리 구할땐 다 -1로 초기화
        cin >> x >> y;
        dist[x][y] = 0;
        bfs(x,y);

        cout << dist[xx][yy] <<"\n";
    }


}

