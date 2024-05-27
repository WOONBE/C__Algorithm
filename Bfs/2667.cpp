#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string arr[25];
bool visited[25][25];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
vector<int> v;

void bfs(int x, int y) {
    int cnt = 1;  // 단지 내 집의 수를 카운트, 시작점 포함해서 1로 초기화
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto nxt = q.front();
        q.pop();
        int x = nxt.first;
        int y = nxt.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && arr[nx][ny] == '1') {
                visited[nx][ny] = true;
                q.push({nx, ny});
                cnt++;
            }
        }
    }

    v.push_back(cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        arr[i] = c;
//        char c;
//        cin >> c;
//        arr[i][j] = c - '0';
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '1' && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }

    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\n";
    }

    return 0;
}
