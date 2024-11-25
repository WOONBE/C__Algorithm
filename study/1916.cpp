#include <iostream>
#include <vector>
#include <queue>
//#include <climits> // INT_MAX 사용
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MX 9987654321
vector<pair<int, int>> v[1001]; // 도시 간 연결 정보 (도착 도시, 비용)
int N, M;                       // 도시 개수와 버스 개수
int start_num, end_num;         // 출발점과 도착점

long long dijkstra(int start) {
    vector<long long> dist(N + 1, MX); // 거리 배열 초기화
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq; // 최소 힙 (비용, 도시)

    dist[start] = 0; // 시작점의 거리는 0
    pq.push({0, start});

    while (!pq.empty()) {
        auto [current_cost, current_city] = pq.top();
        pq.pop();

        // 이미 처리된 거리보다 크면 무시
        if (dist[current_city] < current_cost) continue;

        // 현재 도시에서 이동 가능한 도시들 확인
        for (auto [next_city, next_cost] : v[current_city]) {
            long long new_cost = current_cost + next_cost;

            // 더 작은 비용으로 갱신 가능한 경우
            if (new_cost < dist[next_city]) {
                dist[next_city] = new_cost;
                pq.push({new_cost, next_city});
            }
        }
    }

    return dist[end_num]; // 도착점까지의 최소 비용 반환
}

int main() {
    First;
    cin >> N >> M; // 도시 개수와 버스 개수 입력

    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        v[start].push_back({end, cost});
    }

    cin >> start_num >> end_num; // 출발점과 도착점 입력

    cout << dijkstra(start_num) << "\n"; // 최소 비용 출력

    return 0;
}
