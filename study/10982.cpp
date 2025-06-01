#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef pair<int, int> pii;

int T, N, a, b;
vector<pii> v;
const int INF = 1e9;

int main() {
    First

    cin >> T;

    while (T--) {
        cin >> N;
        v.assign(N, {0, 0});
        int totalA = 0;

        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            v[i] = {a, b};
            totalA += a;
        }

        vector<int> dp(totalA + 1, INF);
        dp[0] = 0;

        for (int i = 0; i < N; i++) {
            int ai = v[i].first;
            int bi = v[i].second;

            // 역순 순회로 이전 값 덮어쓰지 않도록
            for (int t = totalA; t >= 0; --t) {
                if (dp[t] == INF) continue;

                // 오븐 1에 배정
                if (t + ai <= totalA)
                    dp[t + ai] = min(dp[t + ai], dp[t]);

                // 오븐 2에 배정 (덮어쓰기 됨에 유의)
                dp[t] = dp[t] + bi;
            }
        }

        int result = INF;
        for (int t = 0; t <= totalA; t++) {
            result = min(result, max(t, dp[t]));
        }

        cout << result << '\n';
    }

    return 0;
}
