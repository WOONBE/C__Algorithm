//
// Created by 김헌우 on 2024/09/20.
//
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
vector<string> arr;
string str;
vector<vector<int>> board;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int cnt = 0;
struct Ball{
    int x;
    int y;
    char type;
};


queue<Ball> redBall;
queue<Ball> blueBall;
int go_dir = 0;
//빨간 구슬 out되는 최소 횟수, 0 구멍

//10번 이하로 못꺼내면 -1

//파란 구슬이 먼저 빠지면 실패, 같이 빠져도 실패

void moveEnd(int x, int y, int dir){

    while(true){
        if(arr[x+dx[dir]][y+dy[dir]] == '#') return;

        x = x + dx[dir];
        y = y + dy[dir];
    }
}

//방향 미리 체크하는 함수(점이거나 0이면 이동 가능)
bool check(int x, int y){
    for(int dir=0; dir<4; dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(arr[nx][ny] == '#') continue;
        if(arr[nx][ny] == '.' || arr[nx][ny] == '0'){
            go_dir = dir;
            return true;
        }
    }
    return false;
}
//기울이는 함수, #나타날때까지 계속 이동, 좌표를 1로 표시
int play(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j] == 'B'){
                blueBall.push({i,j,arr[i][j]});
            }
            if(arr[i][j] == 'R'){
                redBall.push({i,j,arr[i][j]});
            }
        }
    }



    //한번 기울였을때 둘다 가능하면 r,b 다 이동
    while(true){
        //이동가능하면 계속 한방향 이동
        //q에서 pop하고 이동시킨뒤에 다시 q에 in
        auto blue_cur = blueBall.front(); blueBall.pop();

        auto red_cur = redBall.front(); redBall.pop();

        //하나의 반복문에서 둘다 처리해야할듯
        if(check(red_cur.x,red_cur.y)){

            int red_nx = red_cur.x + dx[go_dir];
            int red_ny = red_cur.y + dy[go_dir];
//            if(arr[red_nx][red_ny] == '0'){
//                cnt ++;
//                return cnt;
//            }
//            else if(arr[red_nx][red_ny] == '.'){
//                redBall.push({red_nx,red_ny,'R'});
//            }

        }



    }

}



void input(){
    cin >> n >> m;
    arr.resize(n);
    board.resize(n, vector<int> (m,0));
    for(int i=0; i<n; i++){
        cin >> str;
        arr[i] = str;
    }

}
int main(){
    First

    input();
    play();






}