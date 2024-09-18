#include <iostream>
#include <vector>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k;

vector<vector<int>> v;
vector<vector<int>> dp;

int dfs(int idx, int weight) {
    // 현재 무게가 배낭의 최대 무게를 초과하면 종료
    if (weight > k) {
        return 0;
    }

    // 모든 물건을 고려한 경우 종료
    if (idx >= n) {
        return 0;
    }

    // 이미 계산된 값이 있다면 그 값을 반환
    if (dp[idx][weight] != -1) {
        return dp[idx][weight];
    }

    // 물건을 넣지 않는 경우
    int withoutCurrent = dfs(idx + 1, weight);

    // 물건을 넣는 경우 (현재 물건을 넣을 수 있는지 확인)
    int withCurrent = 0;
    if (weight + v[idx][0] <= k) {  // 현재 물건을 넣어도 무게가 초과하지 않으면
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
