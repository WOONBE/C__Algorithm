#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int ans, n, tot_cal, score, calorie;
vector<pair<int, int>> v;

void init() {
    ans = 0;
    v.clear();
}

void input() {
    cin >> n >> tot_cal;
    for (int i = 0; i < n; i++) {
        cin >> score >> calorie;
        v.push_back({ score, calorie });
    }
}

void solve(int idx, int sum_score, int sum_cal) {
    if (idx == n) {
        if (sum_cal <= tot_cal) {
            ans = max(ans, sum_score);
        }
        return;
    }

    // 현재 음식을 선택하는 경우
    if (sum_cal + v[idx].second <= tot_cal) { //조건문 지정해 줘야함
        solve(idx + 1, sum_score + v[idx].first, sum_cal + v[idx].second);
    }

    // 현재 음식을 선택하지 않는 경우
    solve(idx + 1, sum_score, sum_cal);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        init();
        input();
        solve(0, 0, 0);
        cout << '#' << tc << ' ' << ans << "\n";
    }
    return 0;
}
