#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;


int n;
int arr[21][21];
int vis[21][21];
int curx,cury; //현재 상어 위치
int ans = 0;
int shark_sze = 2;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int fish = 0;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }
}

void find_shark(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 9){
                curx = i;
                cury = j;
                arr[i][j] = 0;
                return;
            }
        }
    }
}


int bfs(){
    queue<pair<int,int>> q;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    memset(vis, 0, sizeof(vis)); //매번 방문여부 초기화

    q.push({curx,cury});

    while (!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny <0 || nx>=n || ny>=n) continue;

            if (vis[nx][ny] != -1) continue; // 이미 방문한 경우 패스

            if(arr[nx][ny] > shark_sze) continue;
            if(arr[nx][ny] == shark_sze){
                curx = nx;
                cury = ny;
                vis[nx][ny] = vis[x][y] + 1;
                q.push({nx,ny});

            } else if (arr[nx][ny] < shark_sze){
                arr[nx][ny] = 0;
                curx = nx;
                cury = ny;
                vis[nx][ny] = vis[x][y] + 1;
                fish++;
                pq.push({nx,ny});

            }

        }
        if(pq.size()==shark_sze){
            shark_sze++;
            fish = 0;
        }
    }
    return vis[curx][cury];
}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    find_shark();
    while(1){
        int sec = bfs();
        ans += sec;
        if(sec == 0){
            break;
        }

    }
    return ans;
}
