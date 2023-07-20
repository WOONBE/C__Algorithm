//
// Created by 김헌우 on 2023/07/20.
//투 포인터 활용, by Ries
#include "bits/stdc++.h"
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M, arr[10000];
    cin >> N >> M;
    for(int i=0; i<N; i++)
        cin >> arr[i];
    int result = 0, sum = 0, lo = 0, hi = 0;
    while(true){
        if(sum >= M) sum -= arr[lo++];
        else if(hi == N) break;
        else sum += arr[hi++];
        if(sum == M) result++;
    }
    cout << result;
}



