#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int C, N, cost, num, ans;
vector<pair<int, int>> v;
int dp[10001];

int main() {
    First

    cin >> C >> N;
    for (int i = 0; i < N; i++) {
        cin >> cost >> num;
        v.push_back({cost, num});
    }

    const int INF = 987654321;
    fill(dp, dp + 10001, INF);
    dp[0] = 0;


    for (int i = 0; i < N; i++) {
        for (int j = v[i].second; j <= 10000; j++) {
            if (dp[j - v[i].second] != INF) {
                dp[j] = min(dp[j], dp[j - v[i].second] + v[i].first);
            }
        }
    }

    ans = INF;
    for (int i = C; i <= 10000; i++) {
        ans = min(ans, dp[i]);
    }

    cout << ans << "\n";
    return 0;
}
