#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[10]; //연결된 노드 저장
int p[10]; //부모 저장
int depth[10]; //깊이 저장

void bfs(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        for (int nxt : adj[cur]) {
            if (p[cur] == nxt) continue;
            q.push(nxt);
            p[nxt] = cur;
            depth[nxt] = depth[cur] + 1;
        }
    }
}

int main() {
    // 그래프 초기화
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3, 4 };
    adj[2] = { 0, 5 };
    adj[3] = { 1, 6 };
    adj[4] = { 1 };
    adj[5] = { 2 };
    adj[6] = { 3, 7 };
    adj[7] = { 6, 8 };
    adj[8] = { 7 };
    adj[9] = {}; // 빈 vector

    // 부모 배열 초기화
    for (int i = 0; i < 10; ++i) {
        p[i] = 0;
    }

    cout << "BFS traversal starting from node 0: ";
    bfs(0); // 시작 노드는 0입니다.
    cout << endl;

    return 0;
}
