//
// Created by 김헌우 on 2023/07/14.
//
#include <bits/stdc++.h>
using namespace std;

// arr[i] = i를 1, 2, 3의 합으로 나타내는 방법의 수
int arr[20];
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    arr[1] = 1; arr[2] = 2; arr[3] = 4;
    for(int i = 4; i < 11; i++)
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
}
