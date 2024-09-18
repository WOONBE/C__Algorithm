//
// Created by 김헌우 on 2024/09/18.
//모든 육지에서 가장 최장거리를 구하면서 그때마다 최대거리 갱신해주는 방식으로 풀이
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<string > arr;
int n,m;
int max_dist = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void bfs(){
    queue<pair<int,int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'L'){
                vector<vector<int>> dist(n+1, vector<int>(m+1,-1));
                q.push({i,j});
                dist[i][j] = 0;
                while(!q.empty()){

                    auto cur = q.front(); q.pop();
                    int x = cur.first;
                    int y = cur.second;

                    for(int dir=0; dir<4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(0<=nx && nx<n && 0<=ny && ny<m && arr[nx][ny] == 'L' && dist[nx][ny] == -1){ //조건 잘못 설정
                            dist[nx][ny] = dist[x][y] + 1;
                            if(dist[nx][ny] > max_dist){
                                max_dist = dist[nx][ny];
                            }
                            q.push({nx,ny});
                        }
                    }
                }


            }
        }
    }

}

void input(){
    cin >> n >> m;
    arr.resize(n);
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        arr[i] = str;
    }
}
int main(){
    First

    input();

    bfs();

    cout << max_dist << "\n";

}