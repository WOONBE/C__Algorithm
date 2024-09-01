#include <iostream>
#include <vector>
using namespace std;

struct game {
    int num;
    int strike;
    int ball;
};

vector<game> v;

// 두 숫자의 스트라이크와 볼의 개수를 계산하는 함수
void calculate(int guess, int actual, int &strike, int &ball) {
    string guessStr = to_string(guess);
    string actualStr = to_string(actual);

    strike = ball = 0;

    // 스트라이크 개수 계산
    for (int i = 0; i < 3; i++) {
        if (guessStr[i] == actualStr[i]) {
            strike++;
        }
    }

    // 볼 개수 계산
    for (int i = 0; i < 3; i++) {
        if (guessStr[i] != actualStr[i] && actualStr.find(guessStr[i]) != string::npos) {
            ball++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    int possible_count = 0;

    // 123부터 987까지 세 자리 숫자를 확인
    for (int i = 123; i <= 987; i++) {
        string s = to_string(i);
        if (s[0] == '0' || s[1] == '0' || s[2] == '0') continue; // 숫자에 0이 포함되면 스킵
        if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) continue; // 숫자에 중복이 있으면 스킵

        bool possible = true;

        for (auto g : v) {
            int strike = 0, ball = 0;
            calculate(i, g.num, strike, ball);

            if (strike != g.strike || ball != g.ball) {
                possible = false;
                break;
            }
        }

        if (possible) {
            possible_count++;
        }
    }

    cout << possible_count << endl;

    return 0;
}
