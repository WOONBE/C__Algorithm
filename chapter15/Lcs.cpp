//
// Created by 김헌우 on 2023/07/15.
//최장공통부분수열 (증가x) str[i][j] = a1의 i-1까지, a2의 j-1까지의 공통 부분 수열 의미
//부분 수열 증가할때 마지막에 1 추가시키는게 제일 효율좋은 방식인건 초록책에 나와았음
#include "bits/stdc++.h"
using namespace std;

int str[1005][1005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string a1,a2;
    cin >> a1 >> a2;

    for(int i=1; i<=a1.length();i++){
        for(int j=1; j<=a2.length();j++){
            if(a1[i-1] == a2[j-1]) str[i][j] = str[i-1][j-1] + 1; //부분 수열이 공통이면 길이 1증가
            else str[i][j] = max(str[i-1][j], str[i][j-1]); //없으면 이전값중 큰값 선택
        }
    }
    cout << str[a1.length()][a2.length()];


}

