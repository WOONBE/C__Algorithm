#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

int maxOverlap(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> pi = getPartialMatch(b);
    int begin = 0, matched = 0;

    while (begin < n) {
        if (matched < m && a[begin + matched] == b[matched]) {
            matched++;
            if (begin + matched == n) {
                return matched;
            }
        } else {
            if (matched == 0) {
                begin++;
            } else {
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        string s;
        cin >> s;
        string s1 = s;
        reverse(s.begin(), s.end());
        int ret = maxOverlap(s1, s);
        cout << s1.size() * 2 - ret << "\n";
    }

    return 0;
}
