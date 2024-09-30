#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
vector<string> board;
int dx[4] = {1, -1, 0, 0};  // 아래, 위, 오른쪽, 왼쪽
int dy[4] = {0, 0, 1, -1};
bool visited[10][10][10][10];

struct State {
    int rx, ry, bx, by, cnt;
};

// 구슬을 해당 방향으로 끝까지 이동시키는 함수
pair<int, int> move(int x, int y, int dir) {
    while (board[x + dx[dir]][y + dy[dir]] != '#' && board[x][y] != 'O') {
        x += dx[dir];
        y += dy[dir];
    }
    return {x, y};
}

int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        if (cur.cnt > 10) return -1;  // 10번을 초과하면 실패
        if (board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
            return cur.cnt;  // 빨간 구슬이 구멍에 빠졌고, 파란 구슬은 빠지지 않음
        }

        for (int dir = 0; dir < 4; dir++) {
            // 빨간 구슬과 파란 구슬을 해당 방향으로 이동
            auto [nrx, nry] = move(cur.rx, cur.ry, dir);
            auto [nbx, nby] = move(cur.bx, cur.by, dir);

            // 파란 구슬이 구멍에 빠지면 실패
            if (board[nbx][nby] == 'O') continue;

            // 두 구슬이 같은 위치에 있을 경우, 더 많이 이동한 구슬을 한 칸 뒤로
            if (nrx == nbx && nry == nby) {
                if (abs(nrx - cur.rx) + abs(nry - cur.ry) > abs(nbx - cur.bx) + abs(nby - cur.by)) {
                    nrx -= dx[dir];
                    nry -= dy[dir];
                } else {
                    nbx -= dx[dir];
                    nby -= dy[dir];
                }
            }

            // 새로운 상태가 방문하지 않은 상태라면 큐에 추가
            if (!visited[nrx][nry][nbx][nby]) {
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, cur.cnt + 1});
            }
        }
    }
    return -1;  // 10번 이내에 해결하지 못하면 -1
}

int main() {
    First;
    cin >> n >> m;
    board.resize(n);

    int rx, ry, bx, by;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            } else if (board[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    // BFS 실행
    int result = bfs(rx, ry, bx, by);
    cout << result << "\n";
    return 0;
}
