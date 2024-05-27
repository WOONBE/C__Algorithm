#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int w,h;
int arr[50][50];
bool visited[50][50];
int dx[8] = {1,0,-1,0,1,-1,1,-1};
int dy[8] = {0,1,0,-1,1,-1,-1,1};


void bfs(int x, int y){
    queue<pair<int,int>> q;
    visited[x][y] = true; //방문처리 안했음
    q.push({x,y});

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && ny>=0 && ny < w && nx < h && !visited[nx][ny] && arr[nx][ny] == 1){
                visited[nx][ny] = true; //w랑 h 제대로 확인(반대로 받는 값이라 반대로 넣음)
                q.push({nx,ny});
            }
        }
    }
}

int main(){
    while(1){
        int cnt = 0;

        cin >> w >> h;
        memset(visited, 0, sizeof(visited));
        memset(arr, 0, sizeof(arr)); //초기화 까먹었음

        if(w == 0 && h == 0){
            break;
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> arr[i][j];
            }
        }

        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(arr[i][j] == 1 && !visited[i][j]){
                    cnt++;
                    bfs(i,j);
                }
            }
        }
        cout << cnt << "\n";
    }


}
