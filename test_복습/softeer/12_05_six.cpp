#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int N,K;
long long arr[101][101];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

long long min_height = 99987654321;
struct Point{
    int x,y,cnt;

};

void bfs(int x, int y, int cnt){

    bool visited[101][101];
    queue<Point> q;
    q.push({x,y,cnt});
    visited[x][y] = true;
    long long mx_height = 0;


    while(!q.empty()){

        auto i = q.front(); q.pop();
        x = i.x;
        y = i.y;
        cnt = i.cnt;

        if(cnt == K-1) {
            min_height = min(min_height, mx_height);
            return;
        }

        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx <0 || ny < 0 || nx>=N || ny>=N) continue;
            if(visited[nx][ny]) continue;
            if(arr[x][y] >= arr[nx][ny])continue;
            mx_height = max(mx_height,(arr[nx][ny] - arr[x][y]));
            q.push({nx,ny,cnt+1});
        }
    }

}
int main(){

    cin >> N >> K;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++) {
            bfs(i,j,1);
        }
    }

    if(min_height == 99987654321){
        cout << -1 << "\n";
    }
    else{
        cout << min_height << "\n";
    }



}