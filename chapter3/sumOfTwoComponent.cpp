//
// Created by 김헌우 on 2023/06/28.
//
#include <bits/stdc++.h>
using namespace std;

int a[1000001]={};
// 각 자연수의 존재 여부를 저장하는 배열, 아래에서 x-a[i]가 1000000보다 큰 경우를 예외처리하기 싫어서 그냥 배열을 최대 200만으로
bool occur[2000001];
int n, x;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    for (int i = 0; i < n; i++) {
        // x-a[i]가 존재하는지 확인(두 쌍을 next_permutation으로 만들어서 지정하는거 보다 그냥 단순히 빼기 넣는게 더 빠르다
        if(x-a[i] > 0 && occur[x-a[i]]) ans++;
        occur[a[i]] = true;
    }
    cout << ans;

}