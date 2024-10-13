#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 987654321

int N;
vector<pair<long long, long long>> ingredients;

int main() {
    First

    cin >> N;
    ingredients.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> ingredients[i].first >> ingredients[i].second;
    }

    long long ans = INF;

    for (int mask = 1; mask < (1 << N); mask++) {
        long long sour = 1; // 신맛 (곱)
        long long bitter = 0; // 쓴맛 (합)


        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                sour *= ingredients[i].first;
                bitter += ingredients[i].second;
            }
        }

        ans = min(ans, abs(sour - bitter));
    }


    cout << ans << "\n";

    return 0;
}
