#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n;
int arr[21][21];
int vis[21][21];
int curx, cury; // 현재 상어 위치
int ans = 0;
int shark_size = 2;
int fish_count = 0;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                curx = i;
                cury = j;
                arr[i][j] = 0; // 아기 상어 초기 위치는 빈 칸으로 설정
            }
        }
    }
}

int bfs() {
    queue<pair<int, int>> q;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    memset(vis, -1, sizeof(vis)); // 방문 여부 초기화

    q.push({curx, cury});
    vis[curx][cury] = 0;

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (vis[nx][ny] != -1) continue; // 이미 방문한 경우 패스
            if (arr[nx][ny] > shark_size) continue; // 상어보다 큰 물고기가 있는 경우 패스

            vis[nx][ny] = vis[x][y] + 1;

            if (arr[nx][ny] != 0 && arr[nx][ny] < shark_size) {
                pq.push({vis[nx][ny], {nx, ny}});
            }
            q.push({nx, ny});
        }
    }

    if (pq.empty()) return 0; // 먹을 물고기가 없는 경우

    auto target = pq.top();
    int dist = target.first;
    int nx = target.second.first;
    int ny = target.second.second;

    curx = nx;
    cury = ny;
    arr[nx][ny] = 0; // 물고기를 먹은 자리 빈 칸으로 설정
    fish_count++;
    if (fish_count == shark_size) {
        shark_size++;
        fish_count = 0;
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    while (1) {
        int sec = bfs();
        if (sec == 0) break; // 더 이상 먹을 수 있는 물고기가 없으면 종료
        ans += sec;
    }
    cout << ans << '\n';
    return 0;
}

