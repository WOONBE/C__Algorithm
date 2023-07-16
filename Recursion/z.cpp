//
// Created by 김헌우 on 2023/06/27.
//
#include <bits/stdc++.h>
using namespace std;

int func(int n, int r, int c){
    if(n == 0) return 0;
    int half = 1<<(n-1);
    if(r < half && c < half) return func(n-1, r, c);
    if(r < half && c >= half) return half*half + func(n-1, r, c-half); //0,1,2,3 기준으로 나눈거 확인
    if(r >= half && c < half) return 2*half*half + func(n-1, r-half, c);
    return 3*half*half + func(n-1, r-half, c-half);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, r, c;
    cin >> n >> r >> c;
    cout << func(n, r, c);
}
