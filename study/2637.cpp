#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
int degree[101];
vector<pair<int, int>> adj[101];
int need[101][101]; //i를 만들기 위해 j가 몇개필요한지 매핑

int main() {
    First
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
        degree[a]++;
    }

    queue<int> q;
    vector<int> basic;

    // 초기 설정: 기본 부품(진입 차수가 0) 찾기
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
            basic.push_back(i);
            need[i][i] = 1;
        }
    }

    // 위상 정렬을 통해 필요한 부품의 개수를 계산
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (auto &i : adj[x]) {
            int nx = i.first;
            int cnt = i.second;

            // 현재 부품 x를 만드는 데 필요한 기본 부품의 수를 누적(j가 몇개 필요한지 누적)
            for (int j = 1; j <= n; j++) {
                need[nx][j] += need[x][j] * cnt;
            }

            degree[nx]--;
            if (degree[nx] == 0) {
                q.push(nx);
            }
        }
    }

    // 최종 제품 n을 만드는 데 필요한 기본 부품만 출력
    for (int i = 1; i <= n; i++) {
        if (need[n][i] > 0) {
            cout << i << ' ' << need[n][i] << '\n';
        }
    }

    return 0;
}
