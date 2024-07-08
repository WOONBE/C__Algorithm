#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int n,m; //n 한변 길이, m 놓을 수 있는 바이러스 개수
int arr[51][51];

int min_sec = 987654321;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int>> virus;

void input(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j]; //이 부분 실수
            if(arr[i][j] == 2){
                virus.push_back({i,j});
                arr[i][j] = 3; //일단 3으로 돌렸다 나중에 2로 back
            }
        }
    }
}

//놓는 함수(백트래킹), 바이러스 퍼지는 시간 count함수
//다놓고 나서 퍼지는 시간 계산

int bfs(){
    int dist[51][51]; //길이(시간) 저장할 함수

    memset(dist, -1, sizeof(dist)); // 놓침
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 2){
                q.push({ i, j });
                dist[i][j] = 0; //놓침
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue; //범위 밖이면
            if(dist[nx][ny] != -1 || arr[nx][ny] == 1) continue; // 놓침
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
            }
        }


    int ret = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 0){
                if(dist[i][j] == -1) return -1; //놓침, 빈칸인에 방문 x시
                ret = max(ret,dist[i][j]); //놓침, 빈칸인데 방문했으면
            }
        }
    }
    return ret;
}

void backtracking(int cnt, int idx){
    if(cnt == m){
        int now_sec = bfs();
        if(now_sec != -1){ //놓침,
            min_sec = min(min_sec, now_sec);
        }
        return ;
    }
    for(int i=idx; i<virus.size(); i++) {
        arr[virus[i].first][virus[i].second] = 2;
        backtracking(cnt + 1, i + 1);//이 부분 실수
        arr[virus[i].first][virus[i].second] = 3;
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    backtracking(0, 0);
    if(min_sec == 987654321){ //놓침
        cout << -1;
    } else{
    cout << min_sec << "\n";
}

}
