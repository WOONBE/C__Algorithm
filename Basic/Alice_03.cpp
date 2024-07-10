#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> now_cnt; // 반복 횟수를 저장하는 스택
    stack<int> now_len; // 현재까지의 길이를 저장하는 스택
    int findLength = 0;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int num = s[i] - '0';
            if (i + 1 < s.size() && s[i + 1] == '(') {
                now_cnt.push(num);
                now_len.push(findLength);
                findLength = 0;
                i++; // '('를 건너뜀
            } else {
                findLength++;
            }
        } else if (s[i] == ')') {
            int cnt = now_cnt.top(); now_cnt.pop();
            findLength *= cnt;
            findLength += now_len.top(); now_len.pop();
        } else {
            findLength++;
        }
    }

    cout << findLength << endl;

    return 0;
}
