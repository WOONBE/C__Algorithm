//
// Created by 김헌우 on 2023/07/30.
//dp로 구현(점화식)
#include <bits/stdc++.h>
using namespace std;

int comb[1002][1002];
int mod = 10007;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 1000; i++){
        comb[i][0] = comb[i][i] = 1; //iCj 의미
        for(int j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j-1])%mod;
    }
    int n, m;
    cin >> n >> m;
    cout << comb[n][m];
}
