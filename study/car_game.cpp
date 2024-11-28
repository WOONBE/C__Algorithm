#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int board[45][15];
int N;
int max_score = 0;

void dfs(int turn, int score) {
    int backup_board[45][15];
    memcpy(backup_board, board, sizeof(board));

    bool visit[15][15] = {false}; // 차고 부분만 체크
    for (int i = 2 * N; i < 3 * N; i++) {
        for (int j = 0; j < N; j++) {
            int flag = backup_board[i][j];
            if (!visit[i - 2 * N][j] && flag != 0) {
                memcpy(board, backup_board, sizeof(backup_board));

                // 터뜨리기
                int minX = i, maxX = i, minY = j, maxY = j;
                queue<pair<int, int>> q;
                q.push({i, j});
                visit[i - 2 * N][j] = true;
                int cnt = 1; // 터지는 칸 수

                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    board[x][y] = 0;
                    minX = min(minX, x);
                    maxX = max(maxX, x);
                    minY = min(minY, y);
                    maxY = max(maxY, y);

                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d], ny = y + dy[d];
                        if (2 * N <= nx && nx < 3 * N && 0 <= ny && ny < N &&
                            !visit[nx - 2 * N][ny] && backup_board[nx][ny] == flag) {
                            visit[nx - 2 * N][ny] = true;
                            q.push({nx, ny});
                            cnt++;
                        }
                    }
                }

                // 블록 내림
                if (turn < 2) { // 첫 번째, 두 번째는 내림
                    for (int col = minY; col <= maxY; col++) {
                        for (int row = maxX; row >= 0; row--) {
                            if (board[row][col] == 0) {
                                for (int up = row - 1; up >= 0; up--) {
                                    if (board[up][col] != 0) {
                                        board[row][col] = board[up][col];
                                        board[up][col] = 0;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    dfs(turn + 1, score + cnt + ((maxX - minX + 1) * (maxY - minY + 1)));
                } else { // 세 번째는 점수 갱신만
                    max_score = max(max_score, score + cnt + ((maxX - minX + 1) * (maxY - minY + 1)));
                    continue;
                }
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < 3 * N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0);
    cout << max_score << "\n";
    return 0;
}
