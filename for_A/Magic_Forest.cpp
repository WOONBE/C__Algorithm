//
// Created by 김헌우 on 2024/09/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int r,c,g_num;
int center, dir;
int dx[4] = {-1,0,1,0};//북,동,남,서
int dy[4] = {0,1,0,-1};

queue<pair<int,int>> q;
vector<vector<int>> arr;
//배열 r,c , 1행부터 시작(막판에 값 1씩 추가)

//북쪽에서만 in 가능

//골렘 5칸, 출구에서만 내리고 출구빼고에서는 탑승 가능(중앙 제외)

//i번 골렘 : 중앙이 ci열이 되는 위치에서 내려옴, 출구는 di쪽에
void move_gol(){

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;







    }


}
//move check도 괜찮을듯
bool check_down(int x, int y){
    int nx = x + dx[2];
    int ny = y + dy[2];


}

//이동 방식 : 1. 밑으로 한칸, 비어있어야 이동가능(3칸이),
void move_down(){


}
//이동 방식 : 2. 1로 못가면 서쪽으로 회전하면서 down(서쪽칸이 비어야함) + 출구 이동

void move_west(){

}
//이동 방식 : 3. 동쪽으로 회전하면서 down, 시계방향 회전
void move_east(){


}

//다른 곳과 인접 : 정령 이동 로직
void move_fairy(){


}

//정령 최종 위치의 행 번호의 합
void calulate(){


}

//숲 벗어나면 배열 초기화하고 새로 시작
void clear_array(){


}


//입력
void input(){
    cin >> r >> c >> g_num;
    arr.resize(r+1, vector<int>(c+1,0));

    for(int i=0; i<g_num; i++){
        cin >> center >> dir;
        q.push({center,dir});
    }
}

int main(){

    First
    input();

//
//    for(int i=0; i<g_num; i++){
//        auto ans = q.front(); q.pop();
//        cout << ans.first << ans.second << "\n";
//    }





}
