//아이디어 구상하는데 실패했음


#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    stack<int> S;

    int cnt = 1; //push를 위한 비교에 사용한다

    string ans; //정답 출력할 string

    while (n--) {
        int t;
        cin >> t;
        while (cnt <= t) {
            S.push(cnt++);
            ans += "+\n";
        }
        if (S.top() != t) {
            cout << "NO\n";
            return 0;
        }
        S.pop();
        ans += "-\n";
    }
    cout << ans;
}