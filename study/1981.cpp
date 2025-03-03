#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
int board[100][100]; // 문제에서 100x100 제한이므로 크기 조정
bool visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int mx_val = 0;
int min_val = 201;

bool bfs(int diff) {
    for (int min_bound = min_val; min_bound <= mx_val; min_bound++) {
        memset(visited, false, sizeof(visited));
        queue<pair<int, int>> q;

        // 이동 가능한 범위 체크
        if (board[0][0] < min_bound || board[0][0] > min_bound + diff) continue;

        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int x = cur.first, y = cur.second;

            if (x == n - 1 && y == n - 1) return true;

            for (int dir = 0; dir < 4; dir++) {
                int nx = x + dx[dir], ny = y + dy[dir];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
                    if (!visited[nx][ny] && board[nx][ny] >= min_bound && board[nx][ny] <= min_bound + diff) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    First
    cin >> n;

    mx_val = 0;
    min_val = 201;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            mx_val = max(mx_val, board[i][j]);
            min_val = min(min_val, board[i][j]);
        }
    }

    int start = 0, end = mx_val - min_val, result = end;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (bfs(mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    cout << result << "\n";
    return 0;
}
