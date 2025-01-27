#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
int arr[11][11];      // 체스판 정보
int diag1[22], diag2[22]; // 대각선 점유 여부 확인
int maxBishop[2];     // 검은색과 흰색 체스판의 최대 비숍 수

void backtrack(int row, int col, int count, int color) {
    if (col >= n) { // 열이 체스판을 넘어가면 다음 행으로
        row++;
        col = (col % 2 == 0) ? 1 : 0; // 다음 행에서 검은색과 흰색 번갈아 처리
    }

    if (row >= n) { // 모든 행을 처리한 경우
        maxBishop[color] = max(maxBishop[color], count);
        return;
    }

    // 비숍을 놓을 수 있는 위치인지 확인
    if (arr[row][col] && !diag1[row + col] && !diag2[row - col + n - 1]) {
        // 비숍 배치
        diag1[row + col] = diag2[row - col + n - 1] = 1;
        backtrack(row, col + 2, count + 1, color);
        // 비숍 제거
        diag1[row + col] = diag2[row - col + n - 1] = 0;
    }

    // 비숍을 놓지 않고 다음 칸으로 진행
    backtrack(row, col + 2, count, color);
}

int main() {
    First

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // 검은색 칸부터 시작
    backtrack(0, 0, 0, 0);
    // 흰색 칸부터 시작
    backtrack(0, 1, 0, 1);

    // 결과 출력
    cout << maxBishop[0] + maxBishop[1] << "\n";

    return 0;
}
