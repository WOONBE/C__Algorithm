#include <iostream>
#include <vector>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N,M,r,c,dir;

//0 북 1 동쪽 2 남쪽 3 서쪽
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int clean_cnt=0;
int arr[51][51];

bool isDust(int x, int y, int direction){
    for(int i=0; i<4; i++){ //와 진짜 ㅂㅅ인가
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx< 0 || ny <0 || nx>=N || ny >=M) continue;
//        if(arr[nx][ny] == 1) continue;
        if(arr[nx][ny] == 0){
            return true;
        }

    }
    return false;
}
int main(){
    First
    cin >> N >> M;
    cin >> r >> c >> dir;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    //1이 벽이고, 0은 청소x칸(2로 바꿔서 마지막에 cnt해줘도 될듯)
    int nowX = r;
    int nowY = c;
    int nowDir = dir;


    while(true){

        //현재칸 판단
        if(arr[nowX][nowY] == 0){
            arr[nowX][nowY] = 2; //현재칸 청소
        }

        //현재칸 주변 판단
        //다 청소됐으면
        if(!isDust(nowX,nowY,nowDir)){
            //한칸 후진
            if(arr[nowX + dx[(nowDir+2) % 4]][nowY + dy[(nowDir+2) % 4]] != 1){
                nowX = nowX + dx[(nowDir+2) % 4];
                nowY = nowY + dy[(nowDir+2) % 4];
                continue;
            }
            else if(arr[nowX + dx[(nowDir+2) % 4]][nowY + dy[(nowDir+2) % 4]] == 1){
                break;
            }
        }
        //다 청소된게 아니면
        else{
            //반시계로 방향 돌림(1이 0, 0이 3
            nowDir = (nowDir + 3) % 4;
            if(arr[nowX + dx[nowDir]][nowY+dy[nowDir]] == 0){
                nowX = nowX + dx[nowDir];
                nowY = nowY+ dy[nowDir];
                continue;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 2){
                clean_cnt++;
            }
        }
    }

//        for(int i=0; i<N; i++){
//            for(int j=0; j<M; j++){
//            cout << arr[i][j] << ' ';
//        }cout << "\n";
//    }

    cout << clean_cnt << "\n";



//    현재 칸이 아직 청소되지 않은 경우, 현재 칸을 청소한다.
//            현재 칸의 주변
//    $4$칸 중 청소되지 않은 빈 칸이 없는 경우,
//    바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진하고 1번으로 돌아간다.
//            바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춘다.
//            현재 칸의 주변
//    $4$칸 중 청소되지 않은 빈 칸이 있는 경우,
//    반시계 방향으로
//    $90^\circ$ 회전한다.
//            바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진한다.
//    1번으로 돌아간다.
//    1 1 1 1 1 1 1 1 1 1
//    1 0 0 0 0 0 0 0 0 1
//    1 0 0 0 1 1 1 1 0 1
//    1 0 0 1 1 0 0 0 0 1
//    1 0 1 1 0 0 0 0 0 1
//    1 0 0 0 0 0 0 0 0 1
//    1 0 0 0 0 0 0 1 0 1
//    1 0 0 2 2 0 1 1 0 1
//    1 0 0 2 2 0 1 1 0 1
//    1 0 0 0 0 0 0 0 0 1
//    1 1 1 1 1 1 1 1 1 1

}


