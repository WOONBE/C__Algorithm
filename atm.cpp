//
// Created by 김헌우 on 2023/07/02.
//
#include "bits/stdc++.h"
using namespace std;

int arr[1001]={};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int min = 0;


    cin >> num;

    for(int i=0;i<num;i++){
        cin >> arr[i]; //여기서 i말고 n으로 입력받게 해놔서 오류
    }

    sort(arr,arr+num);

    for(int i=0;i<num; i++) {
        min += arr[i]*(num-i); //어차피 다 앞에서부터 계속 더해지는거 활용(후에 재귀로 구현해도 좋을듯)

    }
    cout << min << "\n";

}