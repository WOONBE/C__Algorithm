//12865
// Created by 김헌우 on 2023/07/14.
//배열 할당을 적게해서 계속 오류났음, 기존 문제에서 2차원말고 1차원 배열 써서 푸는 방법
#include "bits/stdc++.h"
using namespace std;

int w[100001]; // 무게
int v[100001]; // 가치
int dp[100001];

int N, K; // 물품의 수 N, 준서가 버틸 수 있는 무게 K

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 0; j--) {
            if (w[i] <= j) { // 물건을 넣을수 있다면
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
                // 그 물건을 넣었을 때와 넣지 않았을 때 중 더 큰 값으로 초기화
            }
        }
    }

    cout << dp[K];

    return 0;
}
