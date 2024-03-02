//
// Created by 김헌우 on 2024/03/02.
//
#include <iostream>
#include <algorithm>

using namespace std;
int mag1[8], mag2[8], mag3[8], mag4[8];
int ans, k, num, dir;
void init(){
    ans = 0;
    num = 0;
    dir = 0;
    for(int i=0; i<8; i++){
        mag1[i] = 0;
        mag2[i] = 0;
        mag3[i] = 0;
        mag4[i] = 0;
    }

}
//아마 check 변수라도 둬서 다 퍼져 나가게 해야할듯?

void rot(int num, int dir){
    //입력 번호 확인해서 입력 번호와 옆의 인덱스 체크
    if(num == 1){
        if(mag1[2] != mag2[6] && mag2[2] != mag3[6]){ //서로 다르면 회전
            if(dir == 1){ //1은 시계로 회전,2는 반시계로 회전, 3은 시계로 회전
                int temp = mag1[7];
                for(int i=7; i>0; i--){
                    mag1[i] = mag1[i-1];
                }
                mag1[0] = temp;

                //mag2는 반시계로 회전
                int temp1 = mag2[0];
                for(int i=0; i<7; i++){
                    mag2[i] = mag2[i+1];
                }
                mag2[7] = temp1;

                int temp2 = mag3[7];
                for(int i=7; i>0; i--){
                    mag3[i] = mag3[i-1];
                }
                mag3[0] = temp2;

            }
            else if(dir == 2){ //1 반시계로 회전, 2 시계로 3반시계로
                int temp = mag1[0];
                for(int i=0; i<8; i++){
                    mag1[i] = mag1[i+1];
                }
                mag1[7] = temp;

                int temp1 = mag2[7];
                for(int i=7; i>0; i--){
                    mag2[i] = mag2[i-1];
                }
                mag2[0] = temp1;

                int temp2 = mag3[0];
                for(int i=0; i<8; i++){
                    mag3[i] = mag3[i+1];
                }
                mag3[7] = temp2;


            }//1,2만 회전
        }else if(mag1[2] != mag2[6] && mag2[2] == mag3[6]){
            if(dir == 1){//1 시계 2 반시계
                int temp = mag1[7];
                for(int i=7; i>0; i--){
                    mag1[i] = mag1[i-1];
                }
                mag1[0] = temp;

                //mag2는 반시계로 회전
                int temp1 = mag2[0];
                for(int i=0; i<8; i++){
                    mag2[i] = mag2[i+1];
                }
                mag2[7] = temp1;

            }
            else if(dir == 2){ //1반시계 2 시계
                int temp = mag1[0];
                for(int i=0; i<8; i++){
                    mag1[i] = mag1[i+1];
                }
                mag1[7] = temp;

                int temp1 = mag2[7];
                for(int i=7; i>0; i--){
                    mag2[i] = mag2[i-1];
                }
                mag2[0] = temp1;
            }

        }//다른 경우는 안움직임
    }
    if(num == 2){
        if(dir == 1){//b가 시계로 돌때


        }
    }

}


void input(){
    cin >> k;
    for(int i=0; i<8; i++){
        cin >> mag1[i];
    }
    for(int i=0; i<8; i++){
        cin >> mag2[i];
    }
    for(int i=0; i<8; i++){
        cin >> mag3[i];
    }
    for(int i=0; i<8; i++){
        cin >> mag4[i];
    }

    for(int i=0; i<k; i++){
        cin >> num >> dir;
        rot(num,dir);

    }

}



void Solve(){
    if(mag1[0] == 1){
        ans += 1;
    }
    if(mag2[0] == 1){
        ans += 2;
    }
    if(mag3[0] == 1){
        ans += 4;
    }
    if(mag4[0] == 1){
        ans += 4;
    }



}

int main(){
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        init();
        input();
        Solve();

        cout << '#' << tc << ' ' << ans << "\n";
    }

}
