#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
const ll INF = 1e18; // long long에 맞는 충분히 큰 값

int K, N, R, s, d, l, t;
vector<tuple<int, int, int>> v[101]; // {도착노드, 길이, 통행료}
ll dist[101][10001]; // dist[도시][비용] = 최소 거리

void dijkstra(int srt_node) {
    // 튜플: {총 거리, 현재 노드, 현재까지 쓴 비용}
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            dist[i][j] = INF;
        }
    }

    dist[srt_node][0] = 0;
    pq.push({0, srt_node, 0});

    while (!pq.empty()) {
        auto [cur_dist, cur_node, cur_cost] = pq.top();
        pq.pop();

        if (dist[cur_node][cur_cost] < cur_dist) {
            continue;
        }

        for (auto& edge : v[cur_node]) {
            int nxt_node, nxt_len, nxt_toll;
            tie(nxt_node, nxt_len, nxt_toll) = edge;

            ll new_cost = cur_cost + nxt_toll;
            ll new_dist = cur_dist + nxt_len;

            // 예산을 초과하는 경로는 무시
            if (new_cost > K) continue;

            // (다음 노드, 새로운 비용) 상태로 가는 더 짧은 거리를 발견했다면 갱신
            if (dist[nxt_node][new_cost] > new_dist) {
                dist[nxt_node][new_cost] = new_dist;
                pq.push({new_dist, nxt_node, new_cost});
            }
        }
    }
}

int main() {
    First
    cin >> K >> N >> R;

    for (int i = 0; i < R; i++) {
        cin >> s >> d >> l >> t;
        v[s].push_back({d, l, t});
    }

    dijkstra(1);

    ll ans = INF;
    // N번 도시에 예산 K 이내로 도착한 모든 경우 중 최소 거리를 찾음
    for (int i = 0; i <= K; i++) {
        ans = min(ans, dist[N][i]);
    }

    if (ans == INF) {
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}