#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int charToIdx(char c) {
    if (c == 'R') return 0;
    if (c == 'P') return 1;
    return 2; // 'S'
}

int solve(string &s) {
    int n = s.size();
    vector<int> orig(n);
    for (int i = 0; i < n; ++i) orig[i] = charToIdx(s[i]);

    int INF = INT_MAX;
    int answer = INF;

    for (int start = 0; start < 3; ++start) {
        // dp[i][j]: i번째 사람이 j를 선택했을 때 최소 변경 수
        vector<vector<int>> dp(n, vector<int>(3, INF));
        dp[0][start] = (start == orig[0]) ? 0 : 1;

        for (int i = 1; i < n; ++i) {
            for (int curr = 0; curr < 3; ++curr) {
                for (int prev = 0; prev < 3; ++prev) {
                    if (curr == prev) continue; // 인접 같은 선택 금지
                    if (dp[i - 1][prev] == INF) continue;
                    int cost = (curr == orig[i]) ? 0 : 1;
                    dp[i][curr] = min(dp[i][curr], dp[i - 1][prev] + cost);
                }
            }
        }

        // 끝과 처음이 인접하므로, 마지막(end)와 start가 같으면 안 됨
        for (int end = 0; end < 3; ++end) {
            if (end == start) continue; // 끝과 처음이 같으면 실패
            if (dp[n - 1][end] == INF) continue;
            answer = min(answer, dp[n - 1][end]);
        }
    }

    return answer;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        int res = solve(s);
        cout << "Case #" << t << ": " << res << '\n';
    }
}
