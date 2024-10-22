#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, M, G, R;
int mx_flower = 0;
int arr[51][51]; // 원 배열
int arr2[51][51]; // 원 배열 복사해놓을 배열
int tme[51][51]; // 시간 저장할 배열
queue<pair<int, int>> q; // bfs 한번 돌릴때 쓰는 큐
queue<pair<int, int>> q2; // 돌린 이후에 넣는 값을 저장할 큐
vector<pair<int, int>> canPlant;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs() {
    int now = 1;
    int tans = 0;
    while (true) {
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (arr[x][y] == 5) continue;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (arr[nx][ny] == 0) continue;
                if (arr[nx][ny] <= 2) {
                    arr[nx][ny] = arr[x][y]; // 3, 4로 세팅해놓은 걸로 옮김
                    tme[nx][ny] = now;
                    q2.push({nx, ny});
                    continue;
                }
                if (arr[nx][ny] == 5) continue;
                if (tme[nx][ny] != now) continue;
                if (arr[nx][ny] != arr[x][y]) {
                    tans++;
                    arr[nx][ny] = 5;
                }
            }
        }
        now++;
        if (q2.empty()) break;
        while (!q2.empty()) {
            q.push(q2.front());
            q2.pop();
        }
    }
    mx_flower = max(mx_flower, tans);
}

void dfs(int idx, int g_mask, int r_mask, int g_cnt, int r_cnt) {
    if (g_cnt > G || r_cnt > R) return; // 초록 또는 빨간 배양액의 개수가 초과되면 종료
    if (idx == canPlant.size()) {
        if (g_cnt == G && r_cnt == R) {
            // 배열 초기화 및 BFS 실행
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    arr[i][j] = arr2[i][j];
                    tme[i][j] = 0;
                }
            }
            // 초록 배양액 배치
            for (int i = 0; i < canPlant.size(); i++) {
                if (g_mask & (1 << i)) { // i번째 위치에 초록 배양액 배치
                    int x = canPlant[i].first;
                    int y = canPlant[i].second;
                    arr[x][y] = 3; // 3: 초록 배양액
                    q.push({x, y});
                }
            }
            // 빨간 배양액 배치
            for (int i = 0; i < canPlant.size(); i++) {
                if (r_mask & (1 << i)) { // i번째 위치에 빨간 배양액 배치
                    int x = canPlant[i].first;
                    int y = canPlant[i].second;
                    arr[x][y] = 4; // 4: 빨간 배양액
                    q.push({x, y});
                }
            }
            bfs();
        }
        return;
    }

    // 배양액을 두지 않는 경우
    dfs(idx + 1, g_mask, r_mask, g_cnt, r_cnt);

    // 초록 배양액을 두는 경우
    dfs(idx + 1, g_mask | (1 << idx), r_mask, g_cnt + 1, r_cnt);

    // 빨간 배양액을 두는 경우
    dfs(idx + 1, g_mask, r_mask | (1 << idx), g_cnt, r_cnt + 1);
}

int main() {
    First
    cin >> N >> M >> G >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            arr2[i][j] = arr[i][j];
            if (arr[i][j] == 2) {
                canPlant.push_back({i, j});
            }
        }
    }

    // 비트마스킹을 사용하여 DFS 시작
    dfs(0, 0, 0, 0, 0);

    cout << mx_flower << "\n"; // 최대 꽃의 수 출력
}
