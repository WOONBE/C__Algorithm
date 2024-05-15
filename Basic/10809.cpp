#include <iostream>
#include <string>

using namespace std;


int main() {

    int cnt[26] = { 0 , };

    string s;

    cin >> s;

    for (char i = 'a'; i <= 'z'; i++) {
        cout << (int)s.find(i) << ' ';
    }


    return 0;
}