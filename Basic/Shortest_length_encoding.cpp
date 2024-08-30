#include <iostream>
#include <string>
#include <vector>
using namespace std;


int runLengthEncodingLength(const string& s) {
    int n = s.length();
    int length = 0;
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            length += 1 + to_string(count).length();
            count = 1;
        }
    }
    length += 1 + to_string(count).length();
    return length;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();
    int minLength = n * 2;

    for (int i = 0; i < n; ++i) {

        string shifted = s.substr(n - i) + s.substr(0, n - i);
        int encodedLength = runLengthEncodingLength(shifted);
        minLength = min(minLength, encodedLength);
    }

    cout << minLength << '\n';

    return 0;
}
