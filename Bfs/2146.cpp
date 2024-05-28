#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;



int n;
int arr[101][101];
int island[101][101];
int dist[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int ans = 987654321;
int cnt = 1;
void bfs(int x, int y){ //섬 넘버링
    queue<pair<int,int>> q;
    q.push({x,y});
    island[x][y] = cnt;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >=0 && ny >=0 && nx <n && ny <n&& island[nx][ny] == 0 && arr[nx][ny] == 1){
                island[nx][ny] = cnt;
                q.push({nx,ny});
            }
        }
    }
}
bool isNearSea(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >=0 && ny >=0 && nx <n && ny <n && arr[nx][ny] == 0){
            return true;
        }

    }
    return false; //이거 리턴 범위 잘못됐었음
}

void calc_dist(int x, int y) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    int island_num = island[x][y];

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int cx = cur.first;
        int cy = cur.second;
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < n) { //범위 안일때
                if (dist[nx][ny] == -1) { // 방문하지 않은 곳
                    if (arr[nx][ny] == 0) { // 바다인 경우
                        dist[nx][ny] = dist[cx][cy] + 1;
                        q.push({nx, ny});
                    } else if (island[nx][ny] > 0 && island[nx][ny] != island_num) { // 다른 섬인 경우
                        ans = min(ans, dist[cx][cy]);
                        return;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }


    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 1 && island[i][j] == 0){
                bfs(i,j);
                cnt++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(island[i][j] >= 1 && isNearSea(i,j)){ //섬이면서 바다 근처면
                calc_dist(i,j);
            }
        }
    }

    cout << ans << "\n";

}
