#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    First

    int N;
    cin >> N;

    vector<int> v(N), LIS, sze(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < N; i++) {
        int now = v[i];

        if (LIS.empty() || LIS.back() < now) {
            sze[i] = LIS.size();
            LIS.push_back(now);
        } else {
            int left = 0, right = LIS.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (LIS[mid] < now) left = mid + 1;
                else right = mid;
            }
            LIS[left] = now;
            sze[i] = left;
        }
    }

    // 최장 증가 부분 수열 길이 출력
    cout << LIS.size() << "\n";

    // 역추적
    stack<int> ans;
    int curLength = LIS.size() - 1;

    for (int i = N - 1; i >= 0; i--) {
        if (sze[i] == curLength) {
            ans.push(v[i]);
            curLength--;
        }
    }

    // 결과 출력
    while (!ans.empty()) {
        cout << ans.top() << ' ';
        ans.pop();
    }

    return 0;
}
