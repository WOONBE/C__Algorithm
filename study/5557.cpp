#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
typedef long long ll;

int N;
vector<int> nums;
ll dp[101][21]; // i번째 수까지 계산했을 때 값이 j가 되는 경우의 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    nums.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    memset(dp, 0, sizeof(dp));
    dp[0][nums[0]] = 1; // 첫 번째 수로 시작하는 경우의 수는 1

    for (int i = 1; i < N - 1; i++) {
        for (int sum = 0; sum <= 20; sum++) {
            if (dp[i - 1][sum]) {
                int plus = sum + nums[i];
                int minus = sum - nums[i];
                if (plus <= 20)
                    dp[i][plus] += dp[i - 1][sum];
                if (minus >= 0)
                    dp[i][minus] += dp[i - 1][sum];
            }
        }
    }

    cout << dp[N - 2][nums[N - 1]] << '\n'; // 마지막 수는 결과 값

    return 0;
}
