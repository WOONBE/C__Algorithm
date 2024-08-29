#include <iostream>
#include <vector>
using namespace std;

const int MX = 100001;

int N;
vector<int> adj[MX]; // 인접 리스트
int first; // 선공 점수
int second; // 후공 점수

void input() {
    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// DFS를 이용하여 각 노드에서의 점수를 계산하는 함수
pair<int, int> dfs(int node, int parent, bool is_first_turn) {
    bool is_leaf = true; // 현재 노드가 리프 노드인지 여부를 체크하는 플래그
    int first_score = 0;
    int second_score = 0;

    // 자식 노드를 순회하면서 최적의 선택을 찾음
    bool next_turn = !is_first_turn; // 다음 턴으로 넘김
    for (int next : adj[node]) {
        if (next == parent) continue; // 부모 노드는 건너뜀
        is_leaf = false; // 자식 노드가 있으므로 리프 노드가 아님

        // 자식 노드에서의 점수 계산
        pair<int, int> child_scores = dfs(next, node, next_turn);
        if (is_first_turn) {
            first_score += child_scores.first;
            second_score += child_scores.second;
        } else {
            first_score += child_scores.second;
            second_score += child_scores.first;
        }
    }

    // 리프 노드인 경우에만 현재 노드의 점수를 비교하여 업데이트
    if (is_leaf) {
        if (is_first_turn) {
            if (node > first) {
                first = node;
            }
        } else {
            if (node > second) {
                second = node;
            }
        }
    }

    // 현재 노드에서의 선공과 후공의 점수를 리턴
    return {first_score, second_score};
}

// 각 노드에서의 결과를 판단하는 함수
int solve(int node) {
    first = 0; // 선공 점수 초기화
    second = 0; // 후공 점수 초기화
    dfs(node, -1, true); // DFS로 각 노드에서의 점수 계산

    // 해당 노드에서의 최종 결과 판단
    if (first >= second) {
        return 1; // 선공 승리
    } else {
        return 0; // 후공 승리
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    input(); // 입력 받기

    // 각 노드에서의 결과 출력
    for (int i = 1; i <= N; ++i) {
        cout << solve(i) << "\n";
    }

    return 0;
}
