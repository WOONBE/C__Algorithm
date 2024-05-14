//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    int arr[51][51];
//    int dist[51][51] = {0}; // 거리를 저장할 배열
//
//    queue<pair<int, int>> q;
//
//    // 입력을 받으면서 아기 상어의 위치를 큐에 넣음
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            cin >> arr[i][j];
//            if(arr[i][j] == 1) {
//                q.push({i, j});
//            }
//        }
//    }
//
//    // BFS를 통해 각 칸까지의 거리를 구함
//    while(!q.empty()) {
//        int x = q.front().first;
//        int y = q.front().second;
//        q.pop();
//
//        for(int i = 0; i < 8; i++) {
//            int nx = x + dx[i];
//            int ny = y + dy[i];
//            if(nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] == 0 && dist[nx][ny] == 0) {
//                dist[nx][ny] = dist[x][y] + 1;
//                q.push({nx, ny});
//            }
//        }
//    }
//
//    // 최댓값을 구함
//    int mx = 0;
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < m; j++) {
//            if(mx < dist[i][j]) {
//                mx = dist[i][j];
//            }
//        }
//    }
//
//    cout << mx << endl;
//
//    return 0;
//}
#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int N, M;
int dist[51][51];
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool check(int r, int c) {
    return r >= 0 && r < N && c >= 0 && c < M;
}

void print() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    cin >> N >> M;

    memset(dist, -1, sizeof(dist));

    int val;
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> val;
            if (val == 1) {
                dist[i][j] = 0;
                q.push({i, j, 0});
            }
        }
    }

    while (!q.empty()) {
        auto curr = q.front(); q.pop();
        int r = get<0>(curr);
        int c = get<1>(curr);
        int d = get<2>(curr);

        for (int i = 0; i < 8; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (check(nr, nc)) {
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = d + 1;
                    q.push({nr, nc, d + 1});
                } else {
                    if (dist[nr][nc] > d + 1) {
                        dist[nr][nc] = d + 1;
                        q.push({nr, nc, d + 1});
                    }
                }
            }
        }

//        print();
    }

    int mx = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(mx < dist[i][j]) {
                mx = dist[i][j];
            }
        }
    }

    cout << mx << endl;

    return 0;
}