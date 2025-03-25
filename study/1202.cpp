#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
vector<pair<int, int>> v;
vector<int> c;

void solve() {
    priority_queue<int> pq;

    sort(c.begin(), c.end());
    sort(v.begin(), v.end());

    long long sum = 0;
    int idx = 0;
    for (int i = 0; i < K; i++) {
        int weight = c[i];

        for (int j = idx; j < N; j++) {
            int M = v[j].first;
            int V = v[j].second;

            if (M <= weight) {
                pq.push(V);
                idx++;
            }
            else {
                break;
            }
        }

        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;

    int M, V;
    for (int i = 0; i < N; i++) {
        cin >> M >> V;
        v.push_back({ M, V });
    }

    int C;
    for (int i = 0; i < K; i++) {
        cin >> C;
        c.push_back(C);
    }

    solve();

    return 0;
}