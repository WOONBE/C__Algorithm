//
// Created by 김헌우 on 2023/07/08.
//
#include "bits/stdc++.h";
using namespace std;


int solution(std::vector<int> prices, int k) {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int answer = 0;
    int half = prices.size()/2 ; //반으로 나눠서 계산

    int arr1[half]; //앞부분 저장
    int arr2[half]; //뒷부분 저장
    int arr3[k]; // 뺀 값 저장

    for(int i=0; i<half; i++){ //앞부분 arr1에 in
        arr1[i] = prices[i];
    }
    for(int i=half; i< prices.size(); i++){ //뒷부분 arr2에 in
        arr2[i] = prices[i];
    }
    sort(arr1, arr1+half);
    sort(arr2, arr2+half,greater<>());

    int buy = arr1[0];

    for(int i=0; i<k;i++){
        arr3[i] = arr2[i] - buy;
    }
    for(int i=0; i<k ; i++){
        answer += arr3[i];
    }
    if(answer > 0)
        cout << answer;
    else
        return -1;
}