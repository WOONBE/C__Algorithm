#include <iostream>
#include <queue>
#include <algorithm>

int arr[1001][1001];
int dist[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

using namespace std;
int n, m;
int ans = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    for( int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    queue<pair<int,int>> q;

    for( int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 1){
                q.push({i,j});
            }
            if(arr[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }
//    for(int i=0; i<n; i++){
//        for(int j=0 ;j<m; j++){
//            cout << dist[i][j] << ' ';
//        }
//        cout << "\n";
//    }

    while(!q.empty()){
        auto cur = q.front();q.pop();
        int x = cur.first;
        int y = cur.second;
       //dist[x][y] = 1; 이거 이렇게 했다가 계속 오류뜸

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny >= 0 && nx < n && ny < m && dist[nx][ny] == -1 && arr[nx][ny] == 0){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
//    for(int i=0; i<n; i++){
//        for(int j=0 ;j<m; j++){
//            cout << dist[i][j] << ' ';
//        }
//        cout << "\n";
//    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0; //이부분 체크
            } else{
                ans = max(ans, dist[i][j]);
            }

        }
    }
    cout << ans << "\n";

}
