#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int T, k;
string w;
vector<int> v; // 알파벳 등장 횟수 저장

int main() {
    First
    cin >> T;

    while (T--) {
        cin >> w >> k;
        v.assign(26, 0);
        vector<vector<int>> v2(26); // 각 알파벳의 등장 위치를 저장

        for (int i = 0; i < w.length(); i++) {
            int idx = w[i] - 'a';
            v[idx]++;
            v2[idx].push_back(i);
        }

        int min_len = 1e9;
        int max_len = 0;

        for (int i = 0; i < 26; i++) {
            if (v[i] < k) continue;

            for (int j = 0; j <= v2[i].size() - k; j++) {
                int start = v2[i][j];
                int end = v2[i][j + k - 1];
                int len = end - start + 1;
                min_len = min(min_len, len);
                max_len = max(max_len, len);
            }
        }

        if (min_len == 1e9) {
            cout << -1 << "\n";
        } else {
            cout << min_len << ' ' << max_len << "\n";
        }
    }

    return 0;
}
