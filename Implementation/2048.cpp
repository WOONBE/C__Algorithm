//
// Created by 김헌우 on 2023/07/09.
//12100 구현은 그냥 이거저거 하다 하루에 하나 정도씩 풀자(시간이 너무 많이 소모됨), 양 4방향에서 구현해도 되지만, 한 방향만 구현하고 보드 자체를 돌린다는 아이디어
#include <bits/stdc++.h>
using namespace std;

int board1[21][21];
int board2[21][21];
int n;

void rotate(){ // board2를 시계 방향으로 90도 회전하는 함수, 기존 cctv 문제꺼 가져옴, 기울이는게 가능하니 밑에 왼쪽으로의 병합만 구현하여도 4방향 합치는게 구현 가능(효율적)
    int tmp[21][21];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            tmp[i][j] = board2[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            board2[i][j] = tmp[n-1-j][i];
}

void tilt(int dir){
    while(dir--) rotate();
    for(int i = 0; i < n; i++){
        int tilted[21] = {}; // board2[i]를 왼쪽으로 기울인 결과를 저장할 변수
        int idx = 0; // tilted 배열에서 어디에 삽입해야 하는지 가리키는 변수
        for(int j = 0; j < n; j++){
            if(board2[i][j] == 0) continue;
            if(tilted[idx] == 0) // 삽입할 위치가 비어있을 경우
                tilted[idx] = board2[i][j];
            else if(tilted[idx] == board2[i][j]){// 같은 값을 갖는 블록이 충돌할 경우
                tilted[idx] *= 2;
                idx += 1;
            }
            else{
                idx += 1;
                tilted[idx] = board2[i][j];
            }     // 다른 값을 갖는 블록이 충돌
        }
        for(int j = 0; j < n; j++) board2[i][j] = tilted[j]; // board2[i]에 tilted를 덮어씀
    }
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board1[i][j];

    int mx = 0;
    for(int tmp = 0; tmp < 1024; tmp++){
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board2[i][j] = board1[i][j];
        int brute = tmp;
        for(int i = 0; i < 5; i++){
            int dir = brute % 4;
            brute /= 4;
            tilt(dir);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mx = max(mx, board2[i][j]);
    }
    cout << mx;
}



