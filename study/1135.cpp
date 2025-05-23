#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, num;
vector<int> v[51]; // v[i] : i번 직원의 부하 목록
int dp[51];        // dp[i] : i번 직원이 소식 전하는 데 걸리는 시간

int dfs(int cur) {
    // 기저: 말단 노드인 경우 (부하가 없음)
    if (v[cur].empty()) return 0;

    vector<int> times;
    for (int i : v[cur]) {
        times.push_back(dfs(i)); // 각 부하가 전파하는 데 걸리는 시간
    }

    // 전달 시간이 큰 부하부터 먼저 전화해야 전체 시간이 줄어듦
    sort(times.rbegin(), times.rend()); // 내림차순 정렬

    int maxTime = 0;
    for (int i = 0; i < times.size(); i++) {
        maxTime = max(maxTime, times[i] + i + 1);
    }

    return dp[cur] = maxTime;
}

int main() {
    First
    cin >> N;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num != -1) {
            v[num].push_back(i);
        }
    }

    cout << dfs(0) << '\n';
}
