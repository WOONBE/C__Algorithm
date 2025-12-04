#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

const int MAX = 2000001;
int v[MAX];

int main() {
    First;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int students;
        cin >> students;
        v[students]++;
    }

    ll ans = 0;

    for (int i = 1; i < MAX; i++) {
        ll cnt = 0;

        for (int j = i; j < MAX; j += i) {
            cnt += v[j];
        }

        if (cnt >= 2) {
            ans = max(ans, cnt * i);
        }
    }

    cout << ans << "\n";
    return 0;
}