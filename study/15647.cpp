#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int MAX = 300001;
int N;
vector<pair<int, int>> adj[MAX];
long long subtree_size[MAX];
long long dist_sum[MAX]; // 각 노드의 S(X) 값을 저장할 배열

// 1단계: 서브트리 크기와 기준점(루트 1)의 거리 합을 계산
void dfs1(int u, int p) {
    subtree_size[u] = 1;
    dist_sum[u] = 0;

    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v == p) continue; // 부모 노드로는 가지 않음

        dfs1(v, u);
        subtree_size[u] += subtree_size[v];
        dist_sum[u] += dist_sum[v] + (long long)w * subtree_size[v];
    }
}

// 2단계: 재루팅을 통해 모든 노드의 거리 합을 계산
void dfs2(int u, int p) {
    for (auto& edge : adj[u]) {
        int v = edge.first;
        int w = edge.second;
        if (v == p) continue;

        // 재루팅 공식 적용
        dist_sum[v] = dist_sum[u] + (long long)w * (N - 2 * subtree_size[v]);
        dfs2(v, u);
    }
}

int main() {
    First
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // 1단계: 1번 노드를 기준으로 계산
    dfs1(1, 0);

    // 2단계: 1번 노드의 결과를 바탕으로 재루팅 시작
    dfs2(1, 0);

    // 모든 노드에 대해 계산된 거리 합(S 값) 출력
    for (int i = 1; i <= N; ++i) {
        cout << dist_sum[i] << '\n';
    }

    return 0;
}