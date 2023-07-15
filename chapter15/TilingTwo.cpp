//
// Created by 김헌우 on 2023/07/14.
//기존 타일 1에서 경우가 하나 더 증가함(2x2)
#include <bits/stdc++.h>
using namespace std;

int d[10005];
int mod = 10007;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    d[1] = 1;
    d[2] = 3;//case 하나 더 증가
    for(int i = 3; i <= n; i++) d[i] = (d[i-1]+ 2*d[i-2])%mod;
    cout << d[n];
}

