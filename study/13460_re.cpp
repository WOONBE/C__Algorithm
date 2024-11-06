#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

string arr[11];
int visited[11][11][11][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int N,M;
int Rx,Ry,Bx,By;
struct State{
    int rx;
    int ry;
    int bx;
    int by;
    int cnt;
};
pair<int,int> move(int x,int y, int dir){
    while(true){
        if(arr[x + dx[dir]][y+dy[dir]] =='#' ||  arr[x][y] == 'O') //0 그냥 숫자 번호로 하면 안돌아감
            break;
        else{
            x += dx[dir];
            y += dy[dir];
        }
    }
    return {x,y};
}

long long bfs(int rx,int ry, int bx, int by){
    queue<State> q;
    int cnt = 0;
    q.push({rx,ry,bx,by,cnt});
    visited[rx][ry][bx][by] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();

        if(cur.cnt > 10){
            return -1;
        }
        if(arr[cur.rx][cur.ry] == 'O' && arr[cur.bx][cur.by] != 'O') return cur.cnt;
        for(int i=0; i<4; i++){
            auto [nrx,nry] = move(cur.rx,cur.ry,i);
            auto [nbx,nby] = move(cur.bx,cur.by,i);

            if(arr[nbx][nby] == 'O') continue; //파란공이 빠지면
            //위치가 같으면
            if(nrx == nbx && nry == nby){
                //빨간공이 더 움직였으면 한칸 뒤로
                if(abs(nrx-cur.rx) + abs(nry-cur.ry) > abs(nbx-cur.bx) + abs(nby-cur.by)){
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else{
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }
            if(!visited[nrx][nry][nbx][nby]){
                visited[nrx][nry][nbx][nby] = 1;
                q.push({nrx,nry,nbx,nby,cur.cnt+1}); //이부분 cnt 넣는거 실수
            }
        }
    }
    return -1;
}


int main(){
    First

    cin >> N >> M;

    string s;
    for(int i=0; i<N; i++){
        cin >> arr[i];
        for(int j=0; j<M; j++){
            if(arr[i][j] == 'R'){
                Rx = i;
                Ry = j;
            }
            if(arr[i][j] == 'B'){
                Bx = i;
                By = j;
            }
        }
    }

//    cout << Rx << ' ' << Ry << ' ' << Bx << ' ' << By <<"\n";
    cout << bfs(Rx,Ry,Bx,By) << "\n";
//    cout << move(Rx,Ry,1).first << ' ' << move(Rx,Ry,1).second <<"\n";


}