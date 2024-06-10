#include <iostream>
#include <algorithm>

using namespace std;

char board[20][20];

int n, m;
bool visited[26]; //알파벳 총 갯수
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int mx_cnt = 0;


void dfs(int x, int y, int cnt){
    mx_cnt = max(mx_cnt, cnt);

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <0 || ny<0 || nx>=n || ny>=m) continue;
        if(visited[board[nx][ny] - 65]) continue;
        visited[board[nx][ny] - 65] = true;
        dfs(nx,ny, cnt+1);
        visited[board[nx][ny] - 65] = false;
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j];
        }
    }

    visited[board[0][0] - 65] = true;
    dfs(0,0,1);

    cout << mx_cnt << "\n";
    return 0;
}