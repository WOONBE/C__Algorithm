#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int dx[3] = {1, 0, 0};
int dy[3] = {0, 1, -1};
int N, M;
int arr[1001][1001];
bool visited[1001][1001];
int dp[1001][1001][3];

int backTracking(int x, int y, int dir) {
    if (x == N - 1 && y == M - 1) {
        return arr[x][y];
    }

    int &ret = dp[x][y][dir];
    if (ret != -1) return ret;

    ret = -1e9;
    visited[x][y] = true;

    for (int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                ret = max(ret, backTracking(nx, ny, i) + arr[x][y]);
                visited[nx][ny] = false;
            }
        }
    }
    return ret;
}

int main() {
    First

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    memset(dp, -1, sizeof(dp));
    cout << backTracking(0, 0, 0) << '\n';
}
