#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int measure_salt(const vector<int>& weights, int x) {
    int n = weights.size();
    int sum_w = 0;
    for (int w : weights) sum_w += w;

    // 최대 무게 차이는 sum_w * 2 (offset을 위해)
    int offset = sum_w;
    int max_diff = sum_w * 2;

    // dp[i][diff] = i번째 추까지 고려해서 diff - offset 무게 차이를 만들 수 있는 최소 횟수
    // 초기값을 큰 값으로 세팅 (불가능 상태)
    vector<vector<int>> dp(n + 1, vector<int>(max_diff + 1, INT_MAX));

    // 초기 상태: 0번째 추까지 고려했을 때, 무게 차이 0 가능 (횟수 0)
    dp[0][offset] = 0;

    for (int i = 0; i < n; i++) {
        int w = weights[i];
        for (int diff = 0; diff <= max_diff; diff++) {
            if (dp[i][diff] == INT_MAX) continue;

            int cur_cnt = dp[i][diff];

            // 1) 무게추 사용 안 함 (diff 변화 없음)
            if (dp[i + 1][diff] > cur_cnt) {
                dp[i + 1][diff] = cur_cnt;
            }

            // 2) 무게추를 왼쪽에 올림 => diff + w (소금 쪽에 더함)
            int left_diff = diff + w;
            if (left_diff <= max_diff) {
                if (dp[i + 1][left_diff] > cur_cnt + 1) {
                    dp[i + 1][left_diff] = cur_cnt + 1;
                }
            }

            // 3) 무게추를 오른쪽에 올림 => diff - w (반대편에 더함)
            int right_diff = diff - w;
            if (right_diff >= 0) {
                if (dp[i + 1][right_diff] > cur_cnt + 1) {
                    dp[i + 1][right_diff] = cur_cnt + 1;
                }
            }
        }
    }

    // x가 offset 기준으로 x+offset 위치에 있는지 확인
    int target = x + offset;

    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
        if (dp[i][target] != INT_MAX) {
            ans = min(ans, dp[i][target]);
        }
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    vector<int> weights = {1, 2, 3, 5};
    int x = 14;

    int result = measure_salt(weights, x);
    cout << result << "\n"; // 기대값: 2

    return 0;
}
