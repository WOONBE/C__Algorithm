//
// Created by 김헌우 on 2023/07/28.
//에라토스테네스체 사용
#include <bits/stdc++.h>
using namespace std;

vector<bool> state(1000001, true); //단순 배열보다 메모리 효율이 좋다
void sieve(int n){
    state[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(!state[i]) continue;
        for(int j = i*i; j <= n; j += i)
            state[j] = false;
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    sieve(n);
    for(int i = m; i <= n; i++){
        if(state[i]) cout << i << '\n';
    }
}
