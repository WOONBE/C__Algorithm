#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N;
int ans;

vector<int> populations;
vector<vector<int>> arr;
bool checked[11];
bool visited[11];

void input() {
    cin >> N;
    populations.resize(N + 1, 0);
    arr.resize(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        populations[i] = num;
    }

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++) {
            int num2;
            cin >> num2;
            arr[i][num2] = 1;
            arr[num2][i] = 1;
        }
    }
}

// BFS로 연결 여부 확인
bool bfs(vector<int> v, bool t) {
    if (v.empty()) return false;  // 빈 선거구 처리

    memset(visited, false, sizeof(visited));
    queue<int> q;

    q.push(v[0]);
    visited[v[0]] = true;
    int cnt = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 1; i <= N; i++) {
            if (checked[i] == t && arr[x][i] == 1 && visited[i] == false) {
                visited[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    return v.size() == cnt;
}

// 각각 선거구가 이어져 있는지 판별
bool right() {
    vector<int> a, b;
    for (int i = 1; i <= N; i++) {
        if (checked[i]) a.push_back(i);
        else b.push_back(i);
    }

    if (!bfs(a, true)) return false;
    if (!bfs(b, false)) return false;

    return true;
}

// 이어져 있는 선거구라면 인구 차이의 최솟값 구함
void calculate() {
    int a = 0, b = 0;
    for (int i = 1; i <= N; i++) {
        if (checked[i]) a += populations[i];
        else b += populations[i];
    }
    int result = abs(a - b);
    ans = min(ans, result);
}

// 조합으로 2개로 나눠지는 모든 선거구 생성
void dfs(int x, int cnt) {
    if (cnt >= 1) {
        // 구역이 이어져 있는지 판별
        if (right()) {
            calculate();
        }
    }
    for (int i = x; i <= N; i++) {
         if (checked[i]) continue;
        checked[i] = true;
        dfs(i, cnt + 1);
        checked[i] = false;
    }
}

int main() {
    First
    input();
    ans = 987654321;
    dfs(1, 0);
    if (ans == 987654321) cout << -1;
    else cout << ans;

    return 0;
}
