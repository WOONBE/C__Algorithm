#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

using namespace std;

const int NOT_BOSS = -1;

int N, M, I;
vector<int> empAge;         // 직원 나이
vector<int> empToNode;      // 직원이 위치한 노드 번호
vector<int> nodeEmp;        // 노드에 배정된 직원 번호
vector<vector<int>> revAdj; // 역 인접 리스트 (나의 상관들)

void swapEmp(int a, int b) {
    int aN = empToNode[a];
    int bN = empToNode[b];

    swap(nodeEmp[aN], nodeEmp[bN]);
    swap(empToNode[a], empToNode[b]);
}

int bfs(int emp) {
    int startNode = empToNode[emp];
    int res = INT_MAX;
    vector<bool> visited(N + 1, false);
    queue<int> q;

    visited[startNode] = true;
    for (int next : revAdj[startNode]) {
        visited[next] = true;
        q.push(next);
    }

    if (q.empty()) return NOT_BOSS;

    while (!q.empty()) {
        int curr = q.front(); q.pop();
        int empId = nodeEmp[curr];
        res = min(res, empAge[empId]);
        for (int next : revAdj[curr]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> I;

    empAge.resize(N + 1);
    empToNode.resize(N + 1);
    nodeEmp.resize(N + 1);
    revAdj.resize(N + 1);

    // 나이 입력
    for (int i = 1; i <= N; ++i) {
        cin >> empAge[i];
        empToNode[i] = i;
        nodeEmp[i] = i;
    }

    // 관계 입력
    for (int i = 0; i < M; ++i) {
        int from, to;
        cin >> from >> to;
        revAdj[to].push_back(from);
    }

    // 쿼리 처리
    for (int i = 0; i < I; ++i) {
        string cmd;
        cin >> cmd;

        if (cmd == "T") {
            int a, b;
            cin >> a >> b;
            swapEmp(a, b);
        } else if (cmd == "P") {
            int emp;
            cin >> emp;
            int res = bfs(emp);
            if (res == NOT_BOSS) cout << "*\n";
            else cout << res << "\n";
        }
    }

    return 0;
}
