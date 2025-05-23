#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, P, K;
vector<pair<int, int>> adj[1001]; // {다음 정점, 비용}

// mid: 우리가 지불할 비용의 최댓값 후보
// 이 때, 비용이 mid를 초과하는 간선을 K개 이하 사용해서 1→N 도달 가능한지 확인
bool is_possible(int mid) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N + 1, 1e9);
    dist[1] = 0;
    pq.push({0, 1}); // {비용초과횟수, 현재노드}

    while (!pq.empty()) {
        auto [over_cnt, cur] = pq.top(); pq.pop();
        if (dist[cur] < over_cnt) continue;

        for (auto [next, cost] : adj[cur]) {
            int next_over = over_cnt + (cost > mid ? 1 : 0);
            if (next_over < dist[next]) {
                dist[next] = next_over;
                pq.push({next_over, next});
            }
        }
    }

    return dist[N] <= K;
}

int main() {
    FAST;
    cin >> N >> P >> K;
    for (int i = 0; i < P; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int lo = 0, hi = 1'000'000;
    int answer = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (is_possible(mid)) {
            answer = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << answer << '\n';
}
