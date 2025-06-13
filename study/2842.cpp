#include <bits/stdc++.h>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0);

string arr[51];
int height[51][51], visited[51][51];
int N;
pair<int, int> st;
vector<pair<int, int>> dest;
vector<int> heights;

int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

bool bfs(int low, int high) {
    if (height[st.first][st.second] < low || height[st.first][st.second] > high)
        return false;

    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push(st);
    visited[st.first][st.second] = 1;

    int reached = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        if (arr[x][y] == 'K') reached++;

        for (int dir = 0; dir < 8; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (height[nx][ny] < low || height[nx][ny] > high) continue;

            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }

    return reached == dest.size();
}

int main() {
    First
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            cin >> height[i][j];
            heights.push_back(height[i][j]);

            if (arr[i][j] == 'P') st = {i, j};
            if (arr[i][j] == 'K') dest.push_back({i, j});
        }

    sort(heights.begin(), heights.end());
    heights.erase(unique(heights.begin(), heights.end()), heights.end());

    int ans = 1e9;
    int l = 0, r = 0;

    while (l < heights.size()) {
        while (r < heights.size()) {
            if (bfs(heights[l], heights[r])) {
                ans = min(ans, heights[r] - heights[l]);
                break; // 가능한 피로도 찾았으면 더 줄여보기
            } else {
                r++; // 범위 확장
            }
        }
        l++; // 왼쪽 범위 증가
    }

    cout << ans << '\n';
}
