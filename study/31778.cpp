#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s;
int N, K;
int pCnt[200001]; // 누적 P 개수
int cCnt[200001]; // 누적 C 개수

int main() {
    First

    cin >> N >> K;
    cin >> s;

    int left = 0;
    int right = N - 1;

    // 'P'와 'C' 교환
    while (left < right && K) {
        while (left < N && s[left] != 'C')
            left++;
        while (right >= 0 && s[right] != 'P')
            right--;
        if (left >= right)
            break;
        K--;
        swap(s[left], s[right]);
    }

    // 누적 P 계산
    for (int i = 0; i < N; i++) {
        if (s[i] == 'P') {
            pCnt[i + 1] = pCnt[i] + 1; // i+1 위치에 누적
        } else {
            pCnt[i + 1] = pCnt[i];
        }
    }

    // 누적 C 계산
    for (int i = N - 1; i >= 0; i--) {
        if (s[i] == 'C') {
            cCnt[i] = cCnt[i + 1] + 1;
        } else {
            cCnt[i] = cCnt[i + 1];
        }
    }

    // 결과 계산
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'P') {
            ans += (long long)pCnt[i] * cCnt[i]; // 이전 P 개수와 이후 C 개수 곱
        }
    }

//    for (int i = 1; i <= N; i++) {
//        if (s[i] == 'P') {
//            ans += (long long)pCnt[i - 1] * cCnt[i];
//        }
//    }

    cout << ans << "\n";

    return 0;
}
