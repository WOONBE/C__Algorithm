#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
int n,m;
string arr[101];
int dist[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void bfs(int x, int y){
    queue<pair<int,int>> q;

    q.push({x,y});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && ny >=0 && nx < n && ny<m && arr[nx][ny] == '1' && dist[nx][ny] <= 0){
                dist[nx][ny] = dist[x][y] + 1; //string으로 받으면 string 처리
                q.push({nx,ny});
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        arr[i] = s;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == '1' && dist[i][j] <=0){
                bfs(i,j);

            }
        }
    }
    cout << dist[n-1][m-1] + 1 << "\n";
}
