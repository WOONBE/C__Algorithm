#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

unordered_map<int, int> mp1;
unordered_map<int, int> mp2;
vector<int> v1;
vector<int> v2;
int want, m, n, num;
int cnt = 0;

int main() {
    First;

    cin >> want;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> num;
        v1.push_back(num);
    }

    for (int i = 0; i < n; i++) {
        cin >> num;
        v2.push_back(num);
    }

    // A피자 부분합 구하기
    for (int len = 1; len <= m; len++) { // 길이 len
        int sum = 0;
        for (int i = 0; i < len; i++) sum += v1[i];
        mp1[sum]++;
        if (sum == want) cnt++;

        if (len == m) break; // 전체 다 선택한 경우는 한 번만

        for (int i = 1; i < m; i++) {
            sum -= v1[(i - 1) % m];
            sum += v1[(i + len - 1) % m];
            mp1[sum]++;
            if (sum == want) cnt++;
        }
    }

    // B피자 부분합 구하기
    for (int len = 1; len <= n; len++) {
        int sum = 0;
        for (int i = 0; i < len; i++) sum += v2[i];
        mp2[sum]++;
        if (sum == want) cnt++;

        if (len == n) break;

        for (int i = 1; i < n; i++) {
            sum -= v2[(i - 1) % n];
            sum += v2[(i + len - 1) % n];
            mp2[sum]++;
            if (sum == want) cnt++;
        }
    }

    // A와 B를 조합하여 want를 만드는 경우
    for (auto& [sumA, countA] : mp1) {
        if (mp2.find(want - sumA) != mp2.end()) {
            cnt += countA * mp2[want - sumA];
        }
    }

    cout << cnt << "\n";
}
