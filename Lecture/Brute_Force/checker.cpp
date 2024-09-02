#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>  // For INT_MAX

using namespace std;

struct Point {
    int x, y;
};

int calculate_dist(const Point& a, const Point& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Point> points(n);
    vector<int> arr_x(n), arr_y(n);
    vector<int> answer(n, -1);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
        arr_x[i] = points[i].x;
        arr_y[i] = points[i].y;
    }

    // 모든 (x, y) 쌍을 기준으로 최소 거리 계산
    for (int y : arr_y) {
        for (int x : arr_x) {
            vector<int> dist;

            // (x, y)를 기준으로 거리 계산
            for (const Point& p : points) {
                dist.push_back(calculate_dist(p, {x, y}));
            }

            // 거리 정렬
            sort(dist.begin(), dist.end());

            // 최소 거리 계산
            int tmp = 0;
            for (int i = 0; i < n; ++i) {
                tmp += dist[i];
                if (answer[i] == -1) {
                    answer[i] = tmp;
                } else {
                    answer[i] = min(tmp, answer[i]);
                }
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';

    return 0;
}
