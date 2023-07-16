//
// Created by 김헌우 on 2023/06/30.
//그냥 쉽게 구현
#include "bits/stdc++.h"
using namespace std;

int main(void){
    int arr[202] = {};
    int chk[202] = {}; //count용
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,v;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[i];
        chk[arr[i]] ++; //이부분 햇갈렸음
    }
    cin >> v;
    cout << chk[v];

}