#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int K,H,W;
int board[201][201];
int visited[201][201][31];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int hx[8]={1, 1, 2, 2, -1, -1, -2, -2};
int hy[8] = {2, -2, 1, -1, 2, -2, 1, -1};


void bfs(){

    //x,y,cnt,말과같은 이동횟수
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{0,0},{0,0}});
    visited[0][0][0] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int cnt = cur.second.first;
        int canMove = cur.second.second;

        if(x == H-1 && y == W-1){
            cout << cnt << "\n";
            return;
        }

        //말과 같이 이동이 가능하면
        if(canMove < K){
            for(int dir = 0; dir<8; dir++){
                int nx = x + hx[dir]; //이 부분 실수
                int ny = y + hy[dir];
                if(nx>=0 && ny>=0 && nx<H && ny<W && board[nx][ny] == 0 && visited[nx][ny][canMove +1] == 0){
                    visited[nx][ny][canMove+1] = 1;
                    q.push({{nx,ny},{cnt+1,canMove+1}});
                }
            }

        }
        for(int dir=0; dir<4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx>=0 && ny>=0 && nx<H && ny< W && board[nx][ny] == 0 && visited[nx][ny][canMove] == 0){
                visited[nx][ny][canMove] = 1;
                q.push({{nx,ny},{cnt+1,canMove}});
            }

        }
    }
    cout << -1 << "\n";
}
int main(){
    First
    cin >> K;
    cin >> W >> H;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> board[i][j];
        }
    }
    bfs();

    return 0;


}
