#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int n, m; // n: 한변 길이, m: 놓을 수 있는 바이러스 개수
int arr[51][51];
int min_sec = 987654321;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> virus;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                virus.push_back({i, j});
                arr[i][j] = 3; // 일단 3으로 돌렸다가 나중에 2로 back
            }
        }
    }
}

int bfs() {
    int dist[51][51];
    memset(dist, -1, sizeof(dist)); // 길이(시간) 저장할 배열 초기화
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 2) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue; // 범위 밖이면 패스
            if (dist[nx][ny] != -1 || arr[nx][ny] == 1) continue; // 이미 방문했거나 벽이면 패스

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                if (dist[i][j] == -1) return -1; // 빈 칸인데 방문하지 못한 경우
                ret = max(ret, dist[i][j]);
            }
        }
    }
    return ret;
}

void backtracking(int cnt, int idx) {
    if (cnt == m) {
        int now_sec = bfs();
        if (now_sec != -1) {
            min_sec = min(min_sec, now_sec);
        }
        return;
    }
    for (int i = idx; i < virus.size(); i++) {
        arr[virus[i].first][virus[i].second] = 2;
        backtracking(cnt + 1, i + 1);
        arr[virus[i].first][virus[i].second] = 3;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    backtracking(0, 0);
    cout << (min_sec == 987654321 ? -1 : min_sec) << "\n";
    return 0;
}
