#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];      // 좌표 압축 후 배열
int psum[1002][1002];     // 누적합 배열 (1-indexed)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> cows;
    set<int> x_set, y_set;
    map<int, int> x_map, y_map;
    vector<int> x_vals, y_vals;

    // 입력받고 좌표 집합에 저장
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        cows.push_back({x, y});
        x_set.insert(x);
        y_set.insert(y);
    }

    // x 좌표 압축
    int idx = 1;
    for (int x : x_set) {
        x_map[x] = idx++;
        x_vals.push_back(x);
    }

    // y 좌표 압축
    idx = 1;
    for (int y : y_set) {
        y_map[y] = idx++;
        y_vals.push_back(y);
    }

    // 좌표 배열에 소 위치 저장
    for (auto [x, y] : cows) {
        arr[x_map[x]][y_map[y]]++;
    }


    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] - psum[i][j] + arr[i+1][j+1];
        }
    }

    int ans = INT_MAX;

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {

            int a = psum[i][j];
            int b = psum[i][1000] - a;
            int c = psum[1000][j] - a;
            int d = psum[1000][1000] - a - b - c;

            ans = min(ans, max({ a, b, c, d }));
        }
    }
    cout << ans << '\n';
}
