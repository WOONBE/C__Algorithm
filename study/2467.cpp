#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> v(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int left = 0, right = N - 1;
    int ans_left = 0, ans_right = 0;
    long long closest = 2e9 + 1; // 초기값을 충분히 큰 값으로 설정

    while (left < right) {
        long long sum = (long long)v[left] + v[right];

        // 0에 더 가까운 값을 갱신
        if (abs(sum) < closest) {
            closest = abs(sum);
            ans_left = left;
            ans_right = right;
        }

        // 합에 따라 포인터 이동
        if (sum < 0) {
            left++;
        } else {
            right--;
        }
    }

    // 결과 출력
    cout << v[ans_left] << " " << v[ans_right] << "\n";

    return 0;
}
