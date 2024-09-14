#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> hint;
int answer = 0;

// 주어진 숫자(number)가 조건에 맞는지 확인하는 함수
bool checker(int idx, int number) {
    int _number = hint[idx][0];
    int _strike = hint[idx][1];
    int _ball = hint[idx][2];

    int strike = 0;
    int ball = 0;

    int _A = _number / 100;
    int _B = (_number / 10) % 10;
    int _C = _number % 10;

    int A = number / 100;
    int B = (number / 10) % 10;
    int C = number % 10;

    // A, B, C 중에 0이 있으면 false 반환
    if (A == 0 || B == 0 || C == 0) return false;

    // A, B, C가 서로 다른지 확인
    if (A == B || A == C || B == C) return false;

    // strike 계산
    if (A == _A) strike++;
    if (B == _B) strike++;
    if (C == _C) strike++;

    // ball 계산
    if (A == _B || A == _C) ball++;
    if (B == _A || B == _C) ball++;
    if (C == _A || C == _B) ball++;

    // strike와 ball이 주어진 조건과 일치하는지 확인
    return (strike == _strike && ball == _ball);
}

// 재귀적으로 숫자를 찾는 함수
void recur(int idx, int number) {
    if (idx == n) {
        answer++;
        recur(0, number + 1);
        return;
    }

    if (number == 1000) return;

    if (checker(idx, number)) {
        recur(idx + 1, number);
    } else {
        recur(0, number + 1);
    }
}

int main() {
    cin >> n;
    hint.resize(n, vector<int>(3));

    for (int i = 0; i < n; ++i) {
        cin >> hint[i][0] >> hint[i][1] >> hint[i][2];
    }

    recur(0, 100);
    cout << answer << endl;

    return 0;
}
