#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int N, M;
vector<vector<int>> MAP;
vector<pair<int, int>> houses;

bool isValid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int minDistance(int x, int y) {
    int minDist = INT_MAX;
    for (auto house : houses) {
        int dist = abs(house.first - x) + abs(house.second - y);
        minDist = min(minDist, dist);
    }
    return minDist;
}

int main() {
    cin >> N >> M;
    MAP.resize(N, vector<int>(M));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> MAP[i][j];
            if (MAP[i][j]) {
                houses.push_back({i, j});
            }
        }
    }

    int min_l = INT_MAX;

    // 가로, 세로, 대각선 모두 체크
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (MAP[i][j] == 0) {
                int minDist = minDistance(i, j);
                min_l = min(min_l, minDist);
            }
        }
    }

    cout << min_l << endl;

    return 0;
}
