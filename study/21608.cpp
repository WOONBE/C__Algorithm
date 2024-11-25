#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N;
int student[401][4]; //[x][y] x번 학생이 선호하는 학생리스트
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int seat[21][21];

//좋아하는 사람 있는지 여부 확인하는 함수
//bool isLike(int cur, int x, int y){
//    for(int i=0; i<4; i++){
//        int nx = x + dx[i];
//        int ny = y + dy[i];
//        if(nx < 0 || ny <0 || nx>=N || ny >= N) continue;
//        if(seat[nx][ny] == 0) continue; //빈 좌석이면 패스
//        for(int j=0; j<4; j++){
//            if(student[cur][j] == seat[nx][ny]) return true; //seat 안했음
//        }
//    }
//    return false;
//}

bool isLike(int cur, int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (student[cur][i] == seat[x][y]) {
            return true;
        }
    }
    return false;
}


//앉히는 함수
void sitDown(int num){

    int mx_like_cnt = -1;
    int mx_empty_cnt = -1;
    int recent_x = -1;
    int recent_y = -1;

    for(int i=1; i<=N; i++){

        for(int j=1; j<=N; j++){
            if(seat[i][j] > 0) continue; //이미 배정됐으면 넘어감
            //상하좌우 판별해서 좋아하는 사람 수 세기, 없으면 empty 증가
            int like_cnt = 0;
            int empty_cnt = 0;

            for(int dir = 0; dir<4; dir++){
                int nx = i + dx[dir];
                int ny = j + dy[dir];
                if(nx <=0 || ny<=0 || nx>N || ny>N) continue;
                if(seat[nx][ny] == 0){
                    empty_cnt++;
                }
                else if(isLike(num,nx,ny)) {
                    like_cnt++;
                }

            }

            //empty와 like 비교해서 배정
            if(like_cnt > mx_like_cnt){
                mx_like_cnt = like_cnt;
                mx_empty_cnt = empty_cnt;
                recent_x = i;
                recent_y = j;
            }
            else if(like_cnt == mx_like_cnt){
                if(empty_cnt > mx_empty_cnt){ //이 부분 실수 허
                    mx_empty_cnt = empty_cnt;
                    recent_x = i;
                    recent_y = j;
                }
                else if(empty_cnt == mx_empty_cnt){
                    if(recent_x > i){
                        recent_x = i;
                        recent_y = j;
                    }
                    else if(recent_x == i && recent_y > j){
                        recent_y = j;
                    }
                }
            }
        }

    }
    seat[recent_x][recent_y] = num;  //이부분도 잘못 설정
}

int calculateSatisfaction() {
    int satisfaction = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int cur = seat[i][j];
            int like_cnt = 0;

            for (int dir = 0; dir < 4; dir++) {
                int nx = i + dx[dir];
                int ny = j + dy[dir];

                // 범위 검사
                if (nx <= 0 || ny <= 0 || nx > N || ny > N) continue;

                if (isLike(cur, nx, ny)) {
                    like_cnt++;
                }
            }

            // 만족도 점수 계산
            if (like_cnt == 1) satisfaction += 1;
            else if (like_cnt == 2) satisfaction += 10;
            else if (like_cnt == 3) satisfaction += 100;
            else if (like_cnt == 4) satisfaction += 1000;
        }
    }

    return satisfaction;
}



void input(){
    cin >> N;
    for(int i=1; i<=N*N; i++){
        int student_num;
        cin >> student_num;
        for(int j=0; j<4; j++){
            cin >> student[student_num][j];
        }
        sitDown(student_num);

    }


}

int main(){
    First

    input();

//    for(int i=1; i<=N; i++){
//        for(int j=1; j<=N; j++){
//            cout << seat[i][j] << ' ';
//        }
//        cout << "\n";
//    }

    cout << calculateSatisfaction() << "\n";

//    for(int i=1; i<=N*N; i++){
//        int stu_num = i;
//        for(int j=0; j<4; j++){
//            cout << student[stu_num][j] << ' ';
//        }
//        cout <<"\n";
//    }





}
