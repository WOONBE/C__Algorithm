#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> adj[32001];
vector<int> visited(32001, 0); // 방문 여부 체크 배열
vector<int> inStack(32001, 0); // DFS 스택 여부 체크 배열
vector<int> list;
bool hasCycle = false; // 사이클 존재 여부 플래그

void dfs(int cur) {
    if (visited[cur]) return;
    visited[cur] = 1;
    inStack[cur] = 1;
    for (auto u : adj[cur]) {
        if (inStack[u]) { // 사이클 발견
            hasCycle = true;
            return;
        }
        if (!visited[u]) {
            dfs(u);
            if (hasCycle) return; // 사이클 발견 시 조기 종료
        }
    }
    inStack[cur] = 0; // DFS 스택에서 제거
    list.push_back(cur);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int start, end;
        cin >> start >> end;
        adj[start].push_back(end);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            if (hasCycle) {

                return 0;
            }
        }
    }

    reverse(list.begin(), list.end());
    for (auto u : list) {
        cout << u << ' ';
    }
    cout << "\n";
    return 0;
}
