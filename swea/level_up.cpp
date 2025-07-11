#include <iostream>
#include <vector>
#include <cmath>
#define First ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
typedef long long ll;

void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    ll total_dist = 0;
    for (int i = 0; i < N - 1; ++i) {
        total_dist += abs(v[i+1] - v[i]);
    }
    ll dist = 0;
    for (int i = 1; i < N - 1; ++i) {

        ll dist1 = abs(v[i] - v[i-1]) + abs(v[i+1] - v[i]);
        ll dist2 = abs(v[i+1] - v[i-1]);
        ll dist3 = dist1 - dist2;
        if (dist3 > dist) {
            dist = dist3;
        }
    }
    cout << total_dist - dist << "\n";
    cout.flush();
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}