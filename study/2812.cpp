#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    string s;
    cin >> N >> K >> s;

    stack<char> st;
    int toRemove = K;

    for (char c : s) {
        // 현재 문자가 이전 문자보다 크면 제거
        while (!st.empty() && toRemove > 0 && st.top() < c) {
            st.pop();
            toRemove--;
        }
        st.push(c);
    }

    // 남은 숫자 꺼내기 (앞에서 N-K개만)
    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    reverse(result.begin(), result.end());
    // 정답은 N-K개의 수로 구성
    cout << result.substr(0, N - K) << "\n";

    return 0;
}
