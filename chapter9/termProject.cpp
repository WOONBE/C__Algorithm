//
// Created by 김헌우 on 2023/07/04.
//시간초과 (어떻게든 bfs가야함)
#include "bits/stdc++.h"
using namespace std;
#define X first
#define Y second

int arr[100002];
bool cnt[100002];
int n;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;


    while(t--){
        int team = 0;
        cin >> n;
        for(int i =0; i<n;i++){
            cin >> arr[i];
            if(arr[i]) cnt[arr[i]] = true; //값이 있으면 true로 변경함

        }
        for(int i =1; i<n+1; i++){
            if(!arr[i]){
                team ++;
            }
        }cout << team << "\n";

        for (int i = 0; i < n; i++) {
            fill(arr, arr + n, 0);  //초기화 시키고 한번 더 실행
            fill(cnt, cnt + n, false);
        }


    }return 0;

}