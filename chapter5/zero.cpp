//
// Created by 김헌우 on 2023/06/28.
//10773
#include "bits/stdc++.h"
using namespace std;


int K,sum = 0;
stack<int> S; //밖에 정의 해줘야함
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> K;


    while(K--){
        int n;
        cin >> n;
        if(n==0) S.pop();
        else S.push(n);
    }
    while(!S.empty()){
        sum += S.top();
        S.pop();

    }
    cout << sum;
}
