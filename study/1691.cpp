#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[601][601], r, c;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j, k, x, y;

    cin >> c >> r; // 가로, 세로 입력

    // 초기값 설정: i * j (최악의 경우 모든 조각을 1×1로 나누는 경우)
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            d[i][j] = i * j;
        }
    }

    int blockCount;
    cin >> blockCount; // 이미 나뉜 영역 개수 입력
    for (i = 1; i <= blockCount; i++) {
        cin >> x >> y;
        d[y][x] = 0; // 해당 위치는 이미 1×1이므로 비용 0
    }

    // DP 계산 (최소 자르기 연산 구하기)
    for (i = 1; i <= r; i++) {
        for (j = 1; j <= c; j++) {
            // 세로로 나누기
            for (k = 1; k <= i - k; k++) {
                d[i][j] = min(d[i][j], d[k][j] + d[i - k][j]);
            }
            // 가로로 나누기
            for (k = 1; k <= j - k; k++) {
                d[i][j] = min(d[i][j], d[i][k] + d[i][j - k]);
            }
        }
    }

    cout << d[r][c] << "\n"; // 최소 비용 출력

    return 0;
}
