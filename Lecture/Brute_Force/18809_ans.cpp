#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M;
int g_cnt, r_cnt;
int arr[51][51];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct plant {
    int x;
    int y;
    int type; // 1이면 초록색, 2면 빨간색
    int time;
};

vector<pair<int, int>> plantable; // 배양액을 뿌릴 수 있는 땅의 좌표
int max_flowers = 0;

// BFS 함수: 배양액을 퍼뜨리며 꽃을 피우는 함수
int bfs(vector<pair<int, int>>& green, vector<pair<int, int>>& red) {
    queue<plant> q;
    vector<vector<int>> g_visited(N, vector<int>(M, -1)); // 초록색 방문 시간
    vector<vector<int>> r_visited(N, vector<int>(M, -1)); // 빨간색 방문 시간
    vector<vector<bool>> flowers(N, vector<bool>(M, false)); // 꽃이 핀 여부
    int flower_count = 0;

    // 초록색 배양액 시작점 추가
    for (auto& g : green) {
        q.push({g.first, g.second, 1, 0});
        g_visited[g.first][g.second] = 0;
    }

    // 빨간색 배양액 시작점 추가
    for (auto& r : red) {
        q.push({r.first, r.second, 2, 0});
        r_visited[r.first][r.second] = 0;
    }

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int now_x = cur.x;
        int now_y = cur.y;
        int now_type = cur.type;
        int now_time = cur.time;

        if (flowers[now_x][now_y]) continue; // 이미 꽃이 핀 경우 무시

        for (int i = 0; i < 4; i++) {
            int nx = now_x + dx[i];
            int ny = now_y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (arr[nx][ny] == 0 || arr[nx][ny] == 2) continue; // 호수는 넘어감

            // 초록색 배양액이 퍼질 때
            if (now_type == 1) {
                if (g_visited[nx][ny] == -1 && r_visited[nx][ny] == -1) { // 빨간색이 아직 퍼지지 않은 곳
                    g_visited[nx][ny] = now_time + 1;
                    q.push({nx, ny, 1, now_time + 1});
                } else if (r_visited[nx][ny] == now_time) { // 빨간색과 동시에 도착
                    flowers[nx][ny] = true;
                    flower_count++;
                }
            }
                // 빨간색 배양액이 퍼질 때
            else if (now_type == 2) {
                if (r_visited[nx][ny] == -1 && g_visited[nx][ny] == -1) { // 초록색이 아직 퍼지지 않은 곳
                    r_visited[nx][ny] = now_time + 1;
                    q.push({nx, ny, 2, now_time + 1});
                } else if (g_visited[nx][ny] == now_time) { // 초록색과 동시에 도착
                    flowers[nx][ny] = true;
                    flower_count++;
                }
            }
        }
    }

    return flower_count;
}

// 배양액을 놓는 모든 경우의 수 탐색
void dfs(int start, int g_left, int r_left, vector<pair<int, int>>& green, vector<pair<int, int>>& red) {
    if (g_left == 0 && r_left == 0) {
        // 배양액을 모두 놓은 경우 BFS 수행
        max_flowers = max(max_flowers, bfs(green, red));
        return;
    }

    for (int i = start; i < plantable.size(); i++) {
        if (g_left > 0) {
            green.push_back(plantable[i]);
            dfs(i + 1, g_left - 1, r_left, green, red);
            green.pop_back();
        }
        if (r_left > 0) {
            red.push_back(plantable[i]);
            dfs(i + 1, g_left, r_left - 1, green, red);
            red.pop_back();
        }
    }
}

int main() {
    First
    cin >> N >> M >> g_cnt >> r_cnt;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) {
                plantable.push_back({i, j}); // 배양액을 뿌릴 수 있는 땅 저장
            }
        }
    }

    vector<pair<int, int>> green, red;
    dfs(0, g_cnt, r_cnt, green, red);

    cout << max_flowers << "\n";
    return 0;
}
