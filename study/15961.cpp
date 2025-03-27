#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, d, k, c;
vector<int> sushi;
vector<int> cnt;

int main() {
    FastIO
    cin >> N >> d >> k >> c;

    sushi.resize(N);
    cnt.resize(d + 1, 0);

    for (int i = 0; i < N; ++i) {
        cin >> sushi[i];
    }

    int kind = 0;
    for (int i = 0; i < k; ++i) {
        if (cnt[sushi[i]] == 0) kind++;
        cnt[sushi[i]]++;
    }

    int ans = kind;
    if (cnt[c] == 0) ans++;

    for (int i = 1; i < N; ++i) {
        int remove = sushi[i - 1];
        cnt[remove]--;
        if (cnt[remove] == 0) kind--;

        int add = sushi[(i + k - 1) % N];
        if (cnt[add] == 0) kind++;
        cnt[add]++;

        int temp = kind;
        if (cnt[c] == 0) temp++;
        ans = max(ans, temp);
    }

    cout << ans << '\n';
    return 0;
}
