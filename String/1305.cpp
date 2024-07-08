#include <iostream>
#include <string>
#include <vector>

using namespace std;

// KMP 알고리즘을 사용하여 실패 함수를 구하는 함수
vector<int> getPartialMatch(string N) {
    int m = N.size();
    vector<int> pi(m, 0);
    int begin = 1, matched = 0;
    while (begin + matched < m) {
        if (N[begin + matched] == N[matched]) {
            matched++;
            pi[begin + matched - 1] = matched;
        } else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int L;
    cin >> L;
    string ad;
    cin >> ad;

    vector<int> pi = getPartialMatch(ad);
    int maxMatch = pi.back(); // 가장 긴 접미사와 접두사의 일치 길이

    int minAdLength = L - maxMatch; // 최소 광고의 길이 계산
    cout << minAdLength << "\n";

    return 0;
}
