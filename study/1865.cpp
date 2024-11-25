#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MX 9987654321

int N, M, W;
vector<tuple<int, int, int>> edges; // (start, end, cost)

// 벨만-포드 알고리즘
bool bellman_ford(int start) {
    vector<long long> dist(N + 1, MX);
    dist[start] = 0;

    // N-1번 완화
    for (int i = 0; i < N - 1; i++) {
        for (auto [start, end, cost] : edges) {
            if (dist[start] != MX && dist[start] + cost < dist[end]) {
                dist[end] = dist[start] + cost;
            }
        }
    }

    // 추가 완화를 통해 음수 사이클 확인
    for (auto [start, end, cost] : edges) {
        if (dist[start] != MX && dist[start] + cost < dist[end]) {
            return true; // 음수 사이클 존재
        }
    }

    return false; // 음수 사이클 없음
}

int main() {
    First;

    int TC;
    cin >> TC;

    while (TC--) {
        cin >> N >> M >> W;
        edges.clear();

        for (int i = 0; i < M; i++) {
            int start, end, cost;
            cin >> start >> end >> cost;
//            edges.push_back(make_tuple(1, 2, 3));
            edges.emplace_back(start, end, cost);
            edges.emplace_back(end, start, cost); // 도로는 양방향
        }

        for (int i = 0; i < W; i++) {
            int start, end, cost;
            cin >> start >> end >> cost;
            edges.emplace_back(start, end, -cost); // 웜홀은 단방향, 시간 감소
        }

        // 1번 지점부터 시작하여 음수 사이클 확인
        if (bellman_ford(1)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
