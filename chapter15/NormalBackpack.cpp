//
// Created by 김헌우 on 2023/07/13.
//knapsack 활용
#include "bits/stdc++.h"
using namespace std;

int w[101],v[101];
int possible[101][1000001];
int n,k;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for(int i=1; i<=n;i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) { //i번까지 보고, 배낭의 용량이 j일때의 가치의 합의 최대값
        for (int j = 1; j <= k; j++) {
            if (j - w[i] >= 0) { // i번째 물건을 넣을 수 있다면?
                possible[i][j] = max(possible[i-1][j], possible[i - 1][j - w[i]] + v[i]);
                // 넣지 않을 때와 넣었을 때, 둘 중 더 큰 것으로 초기화
            }
            else{ // i번째 물건을 넣을 수 없다면, 배낭 용량은 같고 넣지 않았을 때의 값으로 초기화
                possible[i][j] = possible[i-1][j];
            }
        }
    }

    cout << possible[n][k];

    return 0;


}
