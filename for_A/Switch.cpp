//
// Created by 김헌우 on 2024/03/03.
//

#include <iostream>

using namespace std;
int n,student;

int swit[101]; //스위치



void input(){
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> swit[i];
    }
    cin >> student;


}

void Solve(){
    int s = 0; //성별
    int idx = 0; //입력 번호

    for(int i=0; i< student; i++){
        cin >> s >> idx;

        //남자일때

        if(s == 1){
            for(int i=idx; i <= n; i++){ //잘 작동
                if(i < n){
                    if(i % idx == 0){
                        swit[i] = !swit[i];
                    }
                }
            }
        }

        //여자일때
        if(s==2){
            swit[idx] = !swit[idx]; //그냥 바꾸고 시작하자
                for(int i=1; i<=n/2; i++){
                    if(idx-i >=1 && idx+i <= n){
                        if(swit[idx-i] == swit[idx+i]){
                            swit[idx-i] = !swit[idx+i];
                            swit[idx+i] = !swit[idx+i];
                        }
                        else{
                            break;

                    }

                    }
                }
        }

    }
}

int main(){
    input();
    Solve();

    int cnt = 1;
    for(int i=1; i<=n; i++){
        cnt += 1;
        cout << swit[i] << ' ';
        if(cnt >20){
            cout << "\n";
            cnt = 1;
        }
    }
}
