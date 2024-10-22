#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> switches(N+1), bulbs(N+1), positions(N+1), dp(N+1), prev(N+1);

    // 스위치 번호 입력
    for (int i = 1; i <= N; ++i) {
        cin >> switches[i];
    }

    // 전구 번호 입력 및 전구 위치 저장
    for (int i = 1; i <= N; ++i) {
        int bulb;
        cin >> bulb;
        positions[bulb] = i;  // 전구 번호에 해당하는 위치 저장
    }

    // 스위치 번호에 맞게 전구 배열로 변환
    for (int i = 1; i <= N; ++i) {
        bulbs[i] = positions[switches[i]];  // 전구가 위치한 스위치의 위치 저장
    }

    // DP 배열 초기화 (LIS 길이 계산)
    fill(dp.begin(), dp.end(), 1);
    int maxLen = 0, lastIndex = 0;

    // LIS 구하기 (이전 요소 추적)
    for (int i = 1; i <= N; ++i) {
        prev[i] = -1;  // 이전 요소 추적
        for (int j = 1; j < i; ++j) {
            if (bulbs[j] < bulbs[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        // 최장 길이 갱신
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            lastIndex = i;
        }
    }

    // 결과 출력: 최장 길이
    cout << maxLen << endl;

    // 최장 증가 부분 수열(LIS) 역추적
    vector<int> sequence;
    while (lastIndex != -1) {
        sequence.push_back(switches[lastIndex]);
        lastIndex = prev[lastIndex];
    }

    // LIS 정렬하여 출력
    sort(sequence.begin(), sequence.end());
    for (int i = 0; i < sequence.size(); ++i) {
        cout << sequence[i] << " ";
    }
    cout << endl;

    return 0;
}
