
//도전할만한 문제임, bfs 4번 돌려도 타임아웃 안걸림
//인접한 곳이 같은섬인 경우 만드는거 참고

#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int board[101][101];
bool vis[101][101]; // 섬을 분류하는 첫 번째 bfs에서 사용
int dist[101][101]; // 다리의 길이를 구하는 두 번째 bfs에서 사용
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n;
bool out(int a, int b){ // Out Of Bounds인지 체크하는 함수
    return a < 0 or a >= n or b < 0 or b >= n;
}

// 섬을 분류하는 첫 번째 bfs
void island(){
    int idx = 1; // 섬의 번호. board를 이 섬의 번호로 갱신할 예정
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] || board[i][j] == 0) continue;
            // 아직 방문하지 않은 육지에 도달
            queue<pair<int,int> > Q;
            Q.push({i,j});
            vis[i][j] = true;
            while(!Q.empty()){
                auto cur = Q.front(); Q.pop();
                board[cur.X][cur.Y] = idx;
                for(int dir = 0; dir < 4; dir++){
                    int nx = cur.X+dx[dir];
                    int ny = cur.Y+dy[dir];
                    if(out(nx,ny) || vis[nx][ny] || board[nx][ny] == 0) continue;
                    Q.push({nx,ny});
                    vis[nx][ny] = true;
                }
            }
            idx++; // 번호를 1 증가시켜 다음 섬에는 1 증가된 값이 기록될 수 있게끔 한다.
        }
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    island();
    for(int i = 0; i < n; i++)
        fill(dist[i],dist[i]+n,-1); //거리 측정땐 다 -1로 초기화
    queue<pair<int,int>> Q;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0){
                dist[i][j] = 0;
                Q.push({i,j}); //섬 별로 한번에 bfs 돌리려고 한번에 출발점 in
            }
        }
    }
    int ans = 999999; //min 사용하기 때문에
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X+dx[dir];
            int ny = cur.Y+dy[dir];
            if(out(nx,ny) || board[nx][ny] == board[cur.X][cur.Y]) // OOB거나 인접한 곳이 같은 섬일 경우
                continue;
            if(board[nx][ny] != 0){ // 인접한 곳이 다른 섬일 경우(위의 if문에서 같은섬은 이미 걸러짐)
                ans = min(ans,dist[nx][ny]+dist[cur.X][cur.Y]); // cur와 (nx, ny) 각각이 육지로부터 떨어진 거리를 합하면 된다.
            }
            else{ // 바다일 경우
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y]+1;
                Q.push({nx,ny});
            }
        }
    }
    cout << ans;
}