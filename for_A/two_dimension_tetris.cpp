//
// Created by 김헌우 on 2024/08/29.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>


using namespace std;

int n; //블록 갯수
int bX,bY,bType; //블록 x,y,타입
int blue[4][4]; //계속 초기화 하면서 값 in
int red[4][6];
int yellow[6][4];
int point, cnt;
struct Tile{
    int x;
    int y;
    int type;
};

queue<Tile> q;

void input(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> bType >> bX >> bY;
        q.push({bX,bY,bType});
    }
}
//입력 후 움직이는 함수, 파란색은 열 끝부터, 노란색은 행 끝부터 배치
void move(){
    memset(blue,0,sizeof(blue)); //매번 초기화
    Tile tile = q.front(); q.pop();
    int tile_x = tile.x;
    int tile_y = tile.y;
    int tile_type = tile.type;

    //타일 타입에 따라 파란색에 배치
    if(tile_type == 1){
        blue[tile_x][tile_y] = 1;
    }else if(tile_type == 2){
        blue[tile_x][tile_y] = 1;
        blue[tile_x][tile_y+1] =1;
    }else{
        blue[tile_x][tile_y] = 1;
        blue[tile_x+1][tile_y] = 1;
    }

    //배치한 타일을 red로 move
    for(int j=5; j>=0; j--){
        if(tile_type == 1 && !red[tile_x][j]){
            red[tile_x][j] = 1;
            break;
        }
        if(tile_type == 2 && !red[tile_x][j] && !red[tile_x][j-1]){
            red[tile_x][j] = 1;
            red[tile_x][j-1] = 1;
            break;
        }
        if(tile_type == 3 && !red[tile_x][j] && !red[tile_x-1][j]){
            red[tile_x][j] = 1;
            red[tile_x-1][j] = 1;
            break;
        }
    }

    //배치한 타일을 yellow로 move
    for(int i = 5; i>=0; i--){
        if(tile_type == 1 && !yellow[i][tile_y]){
            yellow[i][tile_y] = 1;
            break;
        }
        if(tile_type == 2 && !yellow[i][tile_y] && !yellow[i][tile_y+1]){
            yellow[i][tile_y] = 1;
            yellow[i][tile_y+1] = 1;
            break;
        }
        if(tile_type == 3 && !yellow[i][tile_y] && !yellow[i-1][tile_y]){
            yellow[i][tile_y] = 1;
            yellow[i-1][tile_y] = 1;
            break;
        }
    }
}

//입력 후 행, 열 체크해서 터뜨리는 함수
void tetris(){

    //빨간색 체크해서 터뜨리고 오른쪽으로 한칸씩 push
    for(int j=5; j>=2; j--){
        int cnt = 0;
        for(int i=0; i<4; i++){


        }
    }





    //노란색 체크해서 터뜨리고 윗부분 아래로 push





}

//연한칸 체크해서 있으면 미는 함수
void push_area(){

    //빨간색의 연한칸 체크해서 열 갯수만큼 오른쪽 삭제





    //노란색의 연한칸 체크해서 행 갯수만큼 밑으로 삭제


}

//파란,노란색 칸 세는 함수(연한칸 빼고)
void sum_area(){
    for(int i=0; i<4; i++){
        for(int j=2; j<6; j++){
            if(red[i][j] == 1){
                cnt++;
                }
        }
    }

    for(int i=2; i<6; i++){
        for(int j=0; j<4; j++){
            if(yellow[i][j] == 1){
                cnt ++;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    while(!q.empty()){
        move();
    }


    for(int i=0; i<4; i++){
        for(int j=0; j<6;j++){
            cout << red[i][j] << ' ';
        }
        cout << "\n";
    }

    for(int i=0; i<6; i++){
        for(int j=0; j<4;j++){
            cout << yellow[i][j] << ' ';
        }
        cout << "\n";
    }
}