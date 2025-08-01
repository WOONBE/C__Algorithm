#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

using ll = long long;
const ll INF = 1e18;

int N, M, a, b, c;


// {시작, 도착, 비용}
vector<tuple<int, int, int>> edges;
ll dist[501];

bool bellman(int srt) {
    dist[srt] = 0;

    // 1. N-1번 동안 모든 간선에 대해 완화 작업 반복
    for (int i = 1; i < N; i++) {
        for (auto& edge : edges) {
            int from, to, cost;
            tie(from, to, cost) = edge;

            // 시작점이 아직 방문되지 않았으면 건너뜀
            if (dist[from] == INF) continue;

            // 더 짧은 경로 발견 시 갱신
            if (dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }

    // 2. N번째 반복을 통해 음수 사이클 확인
    for (auto& edge : edges) {
        int from, to, cost;
        tie(from, to, cost) = edge;

        if (dist[from] == INF) continue;

        // N-1번 반복 후에도 거리가 갱신된다면 음수 사이클 존재
        if (dist[to] > dist[from] + cost) {
            return true; // 음수 사이클이 존재함을 알림
        }
    }

    return false; // 음수 사이클 없음
}

int main() {
    First

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edges.emplace_back(a, b, c);
    }

    fill(dist, dist + N + 1, INF);

    bool hasNegativeCycle = bellman(1);

    if (hasNegativeCycle) {
        cout << -1 << "\n";
    } else {
        // 2번부터 N번 노드까지의 최단 거리 출력
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF) {
                cout << -1 << "\n";
            } else {
                cout << dist[i] << "\n";
            }
        }
    }
    return 0;
}