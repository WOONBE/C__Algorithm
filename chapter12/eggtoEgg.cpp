//
// Created by 김헌우 on 2023/07/09.
//
#include "bits/stdc++.h"
using namespace std;

int n;
int dur[10],wei[10]; //내구도와 무게 저장할 array

int mx=0;
int num=0; //깨진 계란의 수

void start(int a){

    if(a == n){
        mx = max(mx,num);
        return; //빼먹어서 런타임 오류발생
    }

    if(dur[a] <=0 || num == n-1){
        start(a+1); //이 부분이 핵심 : 내구도가 0 됐거나 다른 계란들이 다 깨졌으면
        return;
    }
    for(int t = 0; t < n; t++){ // t번째 계란을 내려치고 싶다 (이 부분을 좀 복잡하게 푸는 바람에 그냥 더 나은 코드 가져옴)
        if(t == a or dur[t] <= 0) continue;
        dur[a] -= wei[t];
        dur[t] -= wei[a];
        if(dur[a] <= 0) num++;
        if(dur[t] <= 0) num++;
        start(a+1);
        if(dur[a] <= 0) num--;
        if(dur[t] <= 0) num--;
        dur[a] += wei[t];
        dur[t] += wei[a];
    }

}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dur[i] >> wei[i];
    }
    start(0);
    cout << mx;
}


