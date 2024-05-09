#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> MAP(N, vector<int>(M));

    // 집 좌표 저장
    vector<pair<int, int>> houses;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> MAP[i][j];
            if (MAP[i][j]) {
                houses.push_back({i, j});
            }
        }
    }

    int how_many_house = houses.size();
    int min_l = INT_MAX;

    // 가로 체크
    for (int i = 0; i < N; ++i) {
        if (find(MAP[i].begin(), MAP[i].end(), 1) == MAP[i].end()) {
            int temp_max = 0;
            for (auto house : houses) {
                int temp_l = abs(house.first - i);
                temp_max = max(temp_max, temp_l);
            }
            min_l = min(min_l, temp_max);
        }
    }

    // 세로 체크
    for (int j = 0; j < M; ++j) {
        int temp_max = 0;
        bool can_build = true;
        vector<int> cost(how_many_house, INT_MAX);
        for (int i = 0; i < N; ++i) {
            if (MAP[i][j]) {
                can_build = false;
                break;
            }
            for (int h = 0; h < how_many_house; ++h) {
                int temp_l = abs(houses[h].first - i) + abs(houses[h].second - j);
                cost[h] = min(cost[h], temp_l);
            }
        }
        if (can_build) {
            temp_max = *max_element(cost.begin(), cost.end());
            min_l = min(min_l, temp_max);
        }
    }

    // 왼쪽벽 대각선 체크
    for (int i = 0; i < N - 1; ++i) {
        int now_x = i, now_y = 0;
        vector<int> cost(how_many_house, INT_MAX);
        bool can_build = true;
        while (now_x < N && now_y < M) {
            if (MAP[now_x][now_y] == 1) {
                can_build = false;
                break;
            }
            for (int h = 0; h < how_many_house; ++h) {
                int temp_l = abs(houses[h].first - now_x) + abs(houses[h].second - now_y);
                cost[h] = min(cost[h], temp_l);
            }
            now_x++;
            now_y++;
        }
        if (can_build) {
            int temp_max = *max_element(cost.begin(), cost.end());
            min_l = min(min_l, temp_max);
        }
    }

    // 오른쪽벽 대각선 체크
    for (int i = 0; i < N - 1; ++i) {
        int now_x = i, now_y = N-1;
        vector<int> cost(how_many_house, INT_MAX);
        bool can_build = true;
        while (now_x < N && now_y >= 0) {
            if (MAP[now_x][now_y] == 1) {
                can_build = false;
                break;
            }
            for (int h = 0; h < how_many_house; ++h) {
                int temp_l = abs(houses[h].first - now_x) + abs(houses[h].second - now_y);
                cost[h] = min(cost[h], temp_l);
            }
            now_x++;
            now_y--;
        }
        if (can_build) {
            int temp_max = *max_element(cost.begin(), cost.end());
            min_l = min(min_l, temp_max);
        }
    }

    // 위쪽 벽 오른쪽 아래 대각선 체크
    for (int j = 1; j < M - 1; ++j) {
        int now_x = 0, now_y = j;
        vector<int> cost(how_many_house, INT_MAX);
        bool can_build = true;
        while (now_x < N && now_y < M) {
            if (MAP[now_x][now_y] == 1) {
                can_build = false;
                break;
            }
            for (int h = 0; h < how_many_house; ++h) {
                int temp_l = abs(houses[h].first - now_x) + abs(houses[h].second - now_y);
                cost[h] = min(cost[h], temp_l);
            }
            now_x++;
            now_y++;
        }
        if (can_build) {
            int temp_max = *max_element(cost.begin(), cost.end());
            min_l = min(min_l, temp_max);
        }
    }

    // 위쪽 벽 왼쪽 아래 대각선 체크
    for (int j = 1; j < M - 1; ++j) {
        int now_x = 0, now_y = j;
        vector<int> cost(how_many_house, INT_MAX);
        bool can_build = true;
        while (now_x < N && now_y >= 0) {
            if (MAP[now_x][now_y] == 1) {
                can_build = false;
                break;
            }
            for (int h = 0; h < how_many_house; ++h) {
                int temp_l = abs(houses[h].first - now_x) + abs(houses[h].second - now_y);
                cost[h] = min(cost[h], temp_l);
            }
            now_x++;
            now_y--;
        }
        if (can_build) {
            int temp_max = *max_element(cost.begin(), cost.end());
            min_l = min(min_l, temp_max);
        }
    }

    cout << min_l << endl;

    return 0;
}
