//
// Created by 김헌우 on 2023/06/24.
//
#include <bits/stdc++.h>
using namespace std;


int main(void){
    int freq[10] = {};
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,ans = 0;

    cin >> N;

    //자릿수 구하기
    while(N){
        freq[N%10]++;
        N /= 10;
    }
    for(int i = 0; i < 10; i++){  //6,9말고 다른거부터 일단 freq를 구한다
        if(i == 6 || i == 9) continue;
        ans = max(ans, freq[i]);
    }

    ans = max(ans, (freq[6]+freq[9]+1)/2); //6,9의 freq와 이미 생성한 ans와 비교
    cout << ans;

}
