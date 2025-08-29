#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int T, n, m, a, b;
int arr[501];
int degree[501];
bool adj[501][501];

int main() {
    First;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            degree[i] = 0;
            for(int j = 1; j <= n; j++) {
                adj[i][j] = false;
            }
        }

        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                adj[arr[i]][arr[j]] = true;
                degree[arr[j]]++;
            }
        }

        // 2. 순위 변동 처리 (간선 뒤집기)
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (adj[a][b]) { // 기존에 a -> b 였다면 b -> a 로 변경
                swap(a, b);
            }
            adj[b][a] = false;
            degree[a]--;
            adj[a][b] = true;
            degree[b]++;
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        bool is_ambiguous = false;

        while (!q.empty()) {
            if (q.size() > 1) {
                is_ambiguous = true;
                break;
            }

            int cur = q.front();
            q.pop();
            ans.push_back(cur);

            for (int i = 1; i <= n; i++) {
                if (adj[cur][i]) {
                    degree[i]--;
                    if (degree[i] == 0) {
                        q.push(i);
                    }
                }
            }
        }

        if (is_ambiguous) {
            cout << "?\n";
        } else if (ans.size() < n) {
            cout << "IMPOSSIBLE\n";
        } else {
            for (int i : ans) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}