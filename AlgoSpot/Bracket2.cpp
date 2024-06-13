#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isWellMatched(const string& formula) {
    stack<char> s;
    for (char ch : formula) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            if (s.empty()) return false;
            if ((ch == ')' && s.top() != '(') ||
                (ch == '}' && s.top() != '{') ||
                (ch == ']' && s.top() != '[')) {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main() {
    int C;
    cin >> C;
    vector<string> testCases(C);
    cin.ignore();  // To ignore the newline character after the number input

    for (int i = 0; i < C; ++i) {
        getline(cin, testCases[i]);
    }

    for (const string& formula : testCases) {
        if (isWellMatched(formula)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
