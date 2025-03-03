#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 100001;

vector<pair<int, int>> tree[MAX_N]; // (연결된 노드, 가중치)
int N;
int dist[MAX_N]; // 거리 저장 배열

// BFS를 사용하여 가장 먼 노드와 거리 반환
pair<int, int> bfs(int start) {
    memset(dist, -1, sizeof(dist)); // 거리 배열 초기화
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    int farthestNode = start, maxDist = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto &[next, weight] : tree[cur]) {
            if (dist[next] == -1) { // 방문하지 않은 노드
                dist[next] = dist[cur] + weight;
                q.push(next);
                if (dist[next] > maxDist) {
                    maxDist = dist[next];
                    farthestNode = next;
                }
            }
        }
    }

    return {farthestNode, maxDist};
}

// 두 번째 지름 찾기
int findSecondDiameter() {
    // 1. BFS를 이용하여 가장 먼 정점 A 찾기
    pair<int, int> first = bfs(1);
    int A = first.first;

    // 2. BFS를 이용하여 A에서 가장 먼 정점 B 찾기 (트리의 지름 계산)
    pair<int, int> second = bfs(A);
    int B = second.first;
    int treeDiameter = second.second;

    bfs(A);
    int secondDiameterA = 0;
    for (int i = 1; i <= N; i++) {
        if(i == B) continue;
        if (dist[i] <= treeDiameter && dist[i] > secondDiameterA) {
            secondDiameterA = dist[i];
        }
    }


    bfs(B);
    int secondDiameterB = 0;
    for (int i = 1; i <= N; i++) {
        if(i == A) continue;
        if (dist[i] <= treeDiameter && dist[i] > secondDiameterB) {
            secondDiameterB = dist[i];
        }
    }

    // 5. 두 값 중 최대값이 두 번째 지름
    return max(secondDiameterA, secondDiameterB);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    cout << findSecondDiameter() << "\n";

    return 0;
}
