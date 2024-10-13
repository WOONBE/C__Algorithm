#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0}; //우 상 좌 하
vector<pair<int,int>> cctv;

int arr[8][8];
int N,M;
int min_val = 987654321;
//그 길에 있는 항목들 체크하는 함수
void check(int x, int y, int dir){
    dir %= 4;
    while(1){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx <0 || ny <0 || nx>=N || ny>=M) break;
        if(arr[nx][ny] == 6) break;
        if(arr[nx][ny] >0){
            x = nx;
            y = ny;
            continue;
        }
        arr[nx][ny] = -1;
        x = nx;
        y = ny;
    }
}


//dfs로 백트래킹
void dfs(int idx){

    if(idx == cctv.size()){
        int cnt = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 0){
                    cnt ++;
                }
            }
        }
        min_val = min(min_val,cnt);
        return;
    }
    int x = cctv[idx].first;
    int y = cctv[idx].second;
    int tmp[8][8] = {0,};


    for(int dir=0; dir<4; dir++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                tmp[i][j] = arr[i][j];
            }
        }
        if(arr[x][y] == 1){
            check(x,y,dir);

        }
        if(arr[x][y] == 2){
            check(x,y,dir);
            check(x,y,dir+2);
        }
        if(arr[x][y] == 3){
            check(x,y,dir);
            check(x,y,dir+1);
        }
        if(arr[x][y] == 4){
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
        }
        if(arr[x][y] == 5){
            check(x,y,dir);
            check(x,y,dir+1);
            check(x,y,dir+2);
            check(x,y,dir+3);
        }

        dfs(idx+1);

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                arr[i][j] = tmp[i][j];
            }
        }

    }
}


int main(){
    First;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j] > 0 && arr[i][j] < 6){
                cctv.push_back({i,j});
            }
        }
    }
//    check(2,0,0);
//    for(int i=0; i<N; i++){
//        for(int j=0; j<M; j++){
//            cout << arr[i][j];
//        }
//        cout <<"\n";
//    }
    dfs(0);

    cout << min_val << "\n";



}