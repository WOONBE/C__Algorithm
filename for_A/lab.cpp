#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define X first
#define Y second

int board[8][8];
int n, m, ans;
int free_cells = 0;
vector<pair<int, int>> frees; // 빈칸
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

// 바이러스가 전파된 칸의 수를 반환
int bfs() {
    queue<pair<int, int>> q;
    bool vis[8][8] = {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) q.push({ i, j });
        }
    }
    int ret = 0;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] != 0 || vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            q.push({ nx, ny });
            ret++;

        }
    }
    return ret;
}

// k번째 벽의 위치를 선택, idx번째 빈 칸부터 고려
void dfs(int k, int idx) {
    // 벽 3개 세웠으면 bfs로 확인
    if (k == 3) {
        // 바이러스 퍼진 개수 체크
        int virus = bfs();
        // 안전영역 = 빈칸 - 바이러스 퍼진 칸, 3을 빼는 이유는 벽을 3개 세웠으므로, 퍼진 크기 = 전체 바이러스 - 원래 바이러스
        ans = max(free_cells - 3 - virus, ans); //처음부터 빈칸만 카운트하고 갔으므로 전파된 바이러스가 아닌 기존 바이러스는 제외
        return;
    }
    // 각 빈 칸을 벽으로 변경해서 백트래킹 진행
    for (int i = idx; i < frees.size(); i++) {
        board[frees[i].X][frees[i].Y] = 1;
        dfs(k + 1, i + 1);
        board[frees[i].X][frees[i].Y] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {     // 빈 칸 개수와 좌표 저장
                free_cells++;
                frees.push_back({ i, j });
            }
        }
    }
    dfs(0, 0);
    cout << ans;
}


