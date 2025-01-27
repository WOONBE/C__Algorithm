#include <iostream>
#include <string>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string str[9];

bool check(char num, int row, int col) {
    // 같은 행, 같은 열 체크
    for (int i = 0; i < 9; i++) {
        if (str[row][i] == num || str[i][col] == num) {
            return false;
        }
    }

    // 3x3 박스 체크
    int start_row = row - row % 3;
    int start_col = col - col % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (str[start_row + i][start_col + j] == num) {
                return false;
            }
        }
    }
    return true;
}

pair<int, int> findStart() {
    // 빈칸(0) 위치 찾기
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (str[i][j] == '0') { // 빈칸은 '0'으로 처리
                return {i, j};
            }
        }
    }
    return {-1, -1}; // 빈칸이 없으면 종료
}

void solve() {
    pair<int, int> pos = findStart();
    if (pos.first == -1) {
        // 빈칸이 없으면 해결 완료
        return;
    }

    int row = pos.first, col = pos.second;

    for (char num = '1'; num <= '9'; num++) { // 문자 '1' ~ '9'로 처리
        if (check(num, row, col)) {
            str[row][col] = num; // 숫자 배치
            solve();

            // 스도쿠가 해결되었는지 확인
            if (findStart().first == -1) {
                return;
            }

            // 백트래킹
            str[row][col] = '0';
        }
    }
}

int main() {
    First

    // 스도쿠 입력
    for (int i = 0; i < 9; i++) {
        cin >> str[i];
    }

    solve();

    // 결과 출력
    for (int i = 0; i < 9; i++) {
        cout << str[i] << "\n";
    }

    return 0;
}
