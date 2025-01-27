#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 30'000'000 // 무한대 값 설정

struct Edge {
    int s, e, t;
};

bool time_travel(int n, vector<Edge> &edges) {
    vector<int> dist(n + 1, INF); // 거리 배열 초기화
    dist[1] = 0; // 시작점 거리 0 설정

    // 벨만-포드 알고리즘
    for (int i = 1; i < n; i++) {
        for (const auto &edge : edges) {
            int s = edge.s, e = edge.e, t = edge.t;
            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
            }
        }
    }

    // 음수 사이클 확인
    for (const auto &edge : edges) {
        int s = edge.s, e = edge.e, t = edge.t;
        if (dist[e] > dist[s] + t) {
            return true; // 음수 사이클 존재
        }
    }

    return false; // 음수 사이클 없음
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T; // 테스트 케이스 수
    cin >> T;

    while (T--) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;

        // 도로 입력 (양방향)
        for (int i = 0; i < M; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, t});
            edges.push_back({e, s, t});
        }

        // 웜홀 입력 (단방향, 시간 감소)
        for (int i = 0; i < W; i++) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({s, e, -t});
        }

        // 음수 사이클 여부 판단
        if (time_travel(N, edges)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}