#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int N;
vector<pair<int, int>> points;
bool visited[20]; // N <= 20 이므로 충분
long long min_result;

void dfs(int idx, int cnt, int sum_x, int sum_y) {
    if (cnt == N / 2) {
        // 절반은 +, 절반은 - 연산
        int neg_x = 0, neg_y = 0;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) { // 방문 안한곳은 -로 처리
                neg_x += points[i].first;
                neg_y += points[i].second;
            }
        }

        int final_x = sum_x - neg_x;
        int final_y = sum_y - neg_y;
        long long dist_squared = 1LL * final_x * final_x + 1LL * final_y * final_y;

        if (dist_squared < min_result) {
            min_result = dist_squared;
        }
        return;
    }

    if (idx == N) return;

    for (int i = idx; i < N; ++i) {
        visited[i] = true;
        dfs(i + 1, cnt + 1, sum_x + points[i].first, sum_y + points[i].second);
        visited[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cout << fixed;
    cout.precision(12);

    while (T--) {
        cin >> N;
        points.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        min_result = numeric_limits<long long>::max();
        fill(visited, visited + N, false);
        dfs(0, 0, 0, 0); //현재 idx, 실행횟수,
        cout << sqrt(min_result) << '\n';
    }

    return 0;
}
