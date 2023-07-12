//
// Created by 김헌우 on 2023/07/11.
//
#include <bits/stdc++.h>
using namespace std;

int freq[2000001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        freq[a+1000000]++; //범위에 음수가 있어서 더해줌
    }
    for(int i = 0; i <= 2000000; i++){
        while(freq[i]--){ // cnt[i]번 반복
            cout << i-1000000 << '\n'; //출력할땐 더한값 마이너스
        }
    }
}
