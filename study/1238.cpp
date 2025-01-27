#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 1e9 // 무한대 값 설정

using namespace std;

// 전역 변수
int N, M, X;
vector<pair<int, int>> adj[1001]; // 인접 리스트

// 다익스트라 알고리즘 함수
vector<int> dijkstra(int start) {
    vector<int> dist(N + 1, INF); // 시작점에서 각 정점까지의 거리 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // 최소 힙
    dist[start] = 0; // 시작점 거리 0
    pq.push({0, start}); // 우선순위 큐에 시작점 추가

    while (!pq.empty()) {
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // 현재 거리보다 크면 무시
        if (dist[cur_node] < cur_dist) continue;

        // 인접 노드 탐색
        for (auto &edge : adj[cur_node]) {
            int next_node = edge.first;
            int next_dist = edge.second;

            if (dist[next_node] > cur_dist + next_dist) {
                dist[next_node] = cur_dist + next_dist;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    // 간선 정보 입력
    for (int i = 0; i < M; i++) {
        int start, end, time;
        cin >> start >> end >> time;
        adj[start].push_back({end, time});
    }

    // 1. X에서 다른 모든 노드로의 최단 거리 계산
    vector<int> dist_from_x = dijkstra(X);

    // 2. 각 노드에서 X로 가는 최단 거리 계산
    int max_time = 0;
    for (int i = 1; i <= N; i++) {
        if (i == X) continue; // 본인 제외
        vector<int> dist_to_x = dijkstra(i);
        max_time = max(max_time, dist_to_x[X] + dist_from_x[i]);
    }

    // 결과 출력
    cout << max_time << "\n";
    return 0;
}
