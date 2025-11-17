#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// N이 최대 10만이므로 넉넉하게 선언
vector<int> adj[100001];
ll visitors[100001]; // 각 노드가 목적지인 방문객 수
ll max_visitors = 0; // 정답(최대 방문객 수)

// cur: 현재 노드, prev: 부모 노드 (역주행 방지)
// 리턴값: cur 노드와 그 서브트리에 포함된 총 방문객 수 (즉, cur와 prev 사이 간선을 지나는 인원)
ll dfs(int cur, int prev) {
    ll current_sum = visitors[cur]; // 일단 이 노드가 목적지인 사람들을 더함

    for (int next_node : adj[cur]) {
        if (next_node == prev) continue; // 부모 방향으로는 가지 않음

        // 자식 노드에서 올라오는 인원수를 더함
        current_sum += dfs(next_node, cur);
    }

    // 현재 노드(cur)로 들어오는 간선(부모->cur)의 통행량이 current_sum임
    // 단, 루트 노드(1번)로 들어오는 간선은 없으므로 제외하거나 포함해도 상관없음(문제 정의에 따라)
    // 여기서는 모든 간선 중 최대를 구하므로 갱신
    if (cur != 1) { // 1번은 부모 간선이 없으므로 제외
        max_visitors = max(max_visitors, current_sum);
    }

    return current_sum;
}

ll solution(int n, vector<vector<int>> paths, vector<vector<int>> records) {
    // 1. 초기화
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        visitors[i] = 0;
    }
    max_visitors = 0;

    // 2. 양방향 그래프 생성 (트리 구조 잡기 위함)
    for (auto& p : paths) {
        adj[p[0]].push_back(p[1]);
        adj[p[1]].push_back(p[0]);
    }

    // 3. 목적지별 방문객 수 저장
    for (auto& r : records) {
        int node = r[0];
        int count = r[1];
        visitors[node] += count; // 같은 노드에 대한 기록이 여러 번일 수 있으므로 +=
    }

    // 4. 루트(1번)부터 DFS 수행하여 서브트리 합 계산
    dfs(1, 0);

    return max_visitors;
}

int main() {
    // 테스트 케이스 1
    vector<vector<int>> paths1 = {{1, 2}, {2, 4}, {1, 3}, {3, 5}, {3, 6}};
    vector<vector<int>> records1 = {{6, 2}, {5, 3}};
    cout << "Test 1 Result: " << solution(6, paths1, records1) << " (Expected: 5)" << endl;

    // 테스트 케이스 2
    vector<vector<int>> paths2 = {{1, 2}, {1, 3}, {1, 4}};
    vector<vector<int>> records2 = {{2, 100}, {3, 5}, {2, 1}};
    cout << "Test 2 Result: " << solution(4, paths2, records2) << " (Expected: 101)" << endl;

    return 0;
}