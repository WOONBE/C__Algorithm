#include <bits/stdc++.h>
using namespace std;

int T, N, M;
int parent[1002]; // N+2 까지 사용

int Find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Merge(int x, int y) {
    x = Find(x);
    y = Find(y);
    parent[x] = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> M;

        // 부모 초기화: N+1까지 필요
        for (int i = 0; i <= N + 1; i++) {
            parent[i] = i;
        }

        vector<pair<int, int>> requests(M);
        for (int i = 0; i < M; i++) {
            cin >> requests[i].first >> requests[i].second;
        }

        // 종료 범위(b)를 기준으로 오름차순 정렬
        sort(requests.begin(), requests.end(), [](auto& x, auto& y) {
            return x.second < y.second;
        });

        int cnt = 0;
        for (auto [a, b] : requests) {
            int available = Find(a);
            if (available <= b) {
                Merge(available, available + 1);
                cnt++;
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
