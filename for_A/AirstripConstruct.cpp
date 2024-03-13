#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[20][20];
int n, x, ans;

void init() {
    ans = 0;
    // 배열 초기화
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            arr[i][j] = 0;
        }
    }
}

void input() {
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
}

// 행 또는 열 검사하여 활주로 건설 가능한지 확인
bool isConstructable(vector<int>& road) {
    vector<bool> visited(n, false); // 활주로 설치 여부 확인을 위한 배열

    for (int i = 0; i < n - 1; ++i) {
        // 높이가 같으면 넘어감
        if (road[i] == road[i + 1]) continue;
        // 높이 차이가 1 이상인 경우
        if (abs(road[i] - road[i + 1]) > 1) return false;

        // 높이가 1 작은 경우
        if (road[i] - road[i + 1] == -1) {
            // 경사로 설치 가능한지 확인
            for (int j = i; j > i - x; --j) {
                if (j < 0 || road[j] != road[i] || visited[j]) return false;
                visited[j] = true; // 경사로 설치 표시
            }
        }
        // 높이가 1 큰 경우
        else {
            // 경사로 설치 가능한지 확인
            for (int j = i + 1; j <= i + x; ++j) {
                if (j >= n || road[j] != road[i + 1] || visited[j]) return false;
                visited[j] = true; // 경사로 설치 표시
            }
        }
    }
    return true;
}

void solve() {
    // 행 검사
    for (int i = 0; i < n; ++i) {
        vector<int> road;
        for (int j = 0; j < n; ++j) {
            road.push_back(arr[i][j]);
        }
        if (isConstructable(road)) ++ans;
    }

    // 열 검사
    for (int j = 0; j < n; ++j) {
        vector<int> road;
        for (int i = 0; i < n; ++i) {
            road.push_back(arr[i][j]);
        }
        if (isConstructable(road)) ++ans;
    }
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        init();
        input();
        solve();
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
