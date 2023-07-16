//
// Created by 김헌우 on 2023/07/15.
//결국 가장 최소가 되려면 그 수의 제곱근 근처의 수 + 나머지 수

#include "bits/stdc++.h"
using namespace std;

int a[100010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        a[i] = i; //초기값 설정에 실패했었음, 초기값 배열에 원래 그 값 넣어줘야 밑에 식이 성립
        for(int j=1; j*j<=i; j++){
            a[i] = min(a[i],a[i -j*j] + 1); //뺄 수 있으면 빼고 아니면 안뺀 값 중에 최소값 리턴
        }
    }
    cout << a[n];


}