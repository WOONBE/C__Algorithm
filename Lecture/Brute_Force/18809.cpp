#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, M, g_cnt, r_cnt;
int arr[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int>> canPlant;
int max_flower = 0;

struct plant {
    int x, y, type, tme; // x, y 좌표, 배양액 타입 (1: green, 2: red), 확산 시간
};

int bfs(vector<pair<int, int>>& g, vector<pair<int, int>>& r) {
    vector<vector<int>> g_visited(N, vector<int>(M, -1)); // 초록색 배양액 방문 시간
    vector<vector<int>> r_visited(N, vector<int>(M, -1)); // 빨간색 배양액 방문 시간
    vector<vector<bool>> flowers(N, vector<bool>(M, false)); // 꽃이 핀 여부
    queue<plant> q;
    int flower_count = 0;

    // 초록색 배양액 시작점 추가
    for (auto& pos : g) {
        q.push({pos.first, pos.second, 1, 0});
        g_visited[pos.first][pos.second] = 0;
    }

    // 빨간색 배양액 시작점 추가
    for (auto& pos : r) {
        q.push({pos.first, pos.second, 2, 0});
        r_visited[pos.first][pos.second] = 0;
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int now_x = cur.x;
        int now_y = cur.y;
        int now_type = cur.type;
        int now_tme = cur.tme;

        // 이미 꽃이 핀 경우는 무시
        if (flowers[now_x][now_y]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            // 범위를 벗어나거나 호수인 경우
            if (nx < 0 || ny < 0 || nx >= N || ny >= M || arr[nx][ny] == 0)  continue;

            // 초록색 배양액 확산
            if (now_type == 1) {
                if (g_visited[nx][ny] == -1) { // 초록색이 아직 퍼지지 않은 곳
                    g_visited[nx][ny] = now_tme + 1;
                    q.push({nx, ny, 1, now_tme + 1});
                } else if (r_visited[nx][ny] == now_tme + 1 && !flowers[nx][ny]) { // 빨간색과 같은 시간에 도착한 경우
                    flowers[nx][ny] = true;
                    flower_count++;
                }
            }

            // 빨간색 배양액 확산
            if (now_type == 2) {
                if (r_visited[nx][ny] == -1) { // 빨간색이 아직 퍼지지 않은 곳
                    r_visited[nx][ny] = now_tme + 1;
                    q.push({nx, ny, 2, now_tme + 1});
                } else if (g_visited[nx][ny] == now_tme + 1 && !flowers[nx][ny]) { // 초록색과 같은 시간에 도착한 경우
                    flowers[nx][ny] = true;
                    flower_count++;
                }
            }
        }
    }

    return flower_count;
}

void dfs(int idx, int g_left, int r_left, vector<pair<int, int>>& g, vector<pair<int, int>>& r) {
    if (g_left == 0 && r_left == 0) { // 기저 조건: 배양액이 모두 사용된 경우
        max_flower = max(max_flower, bfs(g, r));
        return;
    }

    for (int i = idx; i < canPlant.size(); i++) {
        if (g_left > 0) {
            g.push_back(canPlant[i]);
            dfs(i + 1, g_left - 1, r_left, g, r);
            g.pop_back();
        }
        if (r_left > 0) {
            r.push_back(canPlant[i]);
            dfs(i + 1, g_left, r_left - 1, g, r);
            r.pop_back();
        }
    }
}

int main() {
    First;
    cin >> N >> M >> g_cnt >> r_cnt;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                canPlant.push_back({i, j});
            }
        }
    }

    vector<pair<int, int>> green;
    vector<pair<int, int>> red;
    dfs(0, g_cnt, r_cnt, green, red);

    cout << max_flower << "\n";
}
