#include <iostream>
#include <vector>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
vector<vector<int>> graph, prefix;

int main() {
    First

    cin >> n >> m;
    graph.resize(n + 1, vector<int>(n + 1, 0));
    prefix.resize(n + 1, vector<int>(n + 1, 0));

    // 입력값 받아오기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }

    // prefix 배열 계산
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + graph[i][j];
        }
    }

    // 쿼리 처리
    for (int i = 0; i < m; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        int answer = prefix[y2][x2] - prefix[y2][x1-1] - prefix[y1-1][x2] + prefix[y1-1][x1-1];
        cout << answer << '\n';
    }

    return 0;
}
