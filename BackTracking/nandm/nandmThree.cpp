//
// Created by 김헌우 on 2023/07/07.
//
#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];

void func(int k){ // 현재 k개까지 수를 택했음.
    if(k == m){ // m개를 모두 택했으면
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
        cout << '\n';
        return;
    } //여기까진 동일
    for(int i = 1; i <= n; i++){
        arr[k] = i; // k번째 수를 i로 정함
        func(k+1); // 다음 수를 정하러 한 단계 더 들어감
    } //기존 unused 함수를 제거해야 중복으로 choose하는게 가능하다
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func(0);
}