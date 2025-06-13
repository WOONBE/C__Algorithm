#include <bits/stdc++.h>
using namespace std;

#define Fast ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int N, M, K;
vector<int> candy;
vector<vector<int>> adj;
vector<bool> visited;
vector<pair<int, int>> groups; // {아이 수, 총 사탕 수}

pair<int, int> dfs(int cur) {
    visited[cur] = true;
    int people = 1;
    int totalCandy = candy[cur];

    for (int next : adj[cur]) {
        if (!visited[next]) {
            auto [p, c] = dfs(next);
            people += p;
            totalCandy += c;
        }
    }
    return {people, totalCandy};
}

int main() {
    Fast;
    cin >> N >> M >> K;
    candy.resize(N);
    adj.resize(N);
    visited.assign(N, false);

    for (int i = 0; i < N; ++i)
        cin >> candy[i];

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 연결 요소 구하기
    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            groups.push_back(dfs(i));
        }
    }

    // 배낭 DP
    vector<int> dp(K, 0); // dp[i] = i명의 아이를 울렸을 때 최대 사탕 수
    for (auto [people, candies] : groups) {
        for (int i = K - 1; i >= people; --i) {
            dp[i] = max(dp[i], dp[i - people] + candies);
        }
    }

    cout << dp[K - 1] << '\n';
}
