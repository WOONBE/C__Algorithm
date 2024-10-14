#include <iostream>
#include <vector>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k;

vector<vector<int>> v;
vector<vector<int>> dp;

int dfs(int idx, int weight) {

    if (weight > k) {
        return 0;
    }


    if (idx >= n) {
        return 0;
    }


    if (dp[idx][weight] != -1) {
        return dp[idx][weight];
    }

    // 물건을 넣지 않는 경우
    int withoutCurrent = dfs(idx + 1, weight);


    int withCurrent = 0;
    if (weight + v[idx][0] <= k) {
        withCurrent = dfs(idx + 1, weight + v[idx][0]) + v[idx][1];
    }

    // 더 큰 값을 dp에 저장
    dp[idx][weight] = max(withoutCurrent, withCurrent);

    return dp[idx][weight];
}

void input() {
    cin >> n >> k;

    v.resize(n, vector<int>(2));

    // dp 배열을 n x (k+1) 크기로 설정
    dp.resize(n, vector<int>(k + 1, -1));

    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1]; // 무게와 가치 입력
    }
}

int main() {
    First
    input();

    int max_value = dfs(0, 0);  // 0번째 물건부터 시작, 초기 무게는 0

    cout << max_value << "\n";

    return 0;
}
