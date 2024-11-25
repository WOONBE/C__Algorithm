#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


//아마 dp
//dp[x][y] = 해당 좌표에서 시작했을때 가장 긴 경로
//각 좌표마다 bfs 돌려서 dp에 저장하는 식으로 풀기
int n;
int arr[501][501];
int dp[501][501];
int mx_len = 0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Point{
    int x;
    int y;
    int len;
};

//bfs 돌면서 mx값 갱신
int bfs(int x,int y){
    queue<Point> q;
    int visited[501][501];

    q.push({x,y,1});
    visited[x][y] = 1;

    if(dp[x][y] != -1) {
        return dp[x][y];
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.x;
        int y = cur.y;
        int len = cur.len;
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (arr[x][y] > arr[nx][ny]) continue;
            q.push({nx, ny, len + 1});
            mx_len = max(mx_len,len+1);

        }
    }
    dp[x][y] = max(dp[x][y], mx_len);

    return dp[x][y];
}

int main(){
    First

    cin >> n;
    memset(dp,-1,sizeof(dp));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<n;i++){
        for(int j=0; j<n; j++){
            bfs(i,j);
        }
    }

    cout << mx_len << "\n";


}