#include <iostream>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int T;
ll N, M, K, num, cnt, sum;

int main() {
    First;
    cin >> T;

    while (T--) {
        cin >> N >> M >> K;
        vector<int> v(N);
        cnt = 0;
        sum = 0;

        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }


        for (ll i = 0; i < M; i++) {
            sum += v[i];
        }
        if (sum < K) cnt++;

        if (M == N) {
            cout << cnt << "\n";
            continue;
        }

        for (ll i = 1; i < N; i++) {
            sum -= v[(i - 1) % N];
            sum += v[(i + M - 1) % N];

            if (sum < K) cnt++;

        }

        cout << cnt << "\n";
    }
}
