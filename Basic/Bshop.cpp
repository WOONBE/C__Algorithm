#include <iostream>
using namespace std;

int arr[101][101];
int n, r, c;
int dx[4] = {1, 1, -1, -1}; // 대각선 방향
int dy[4] = {1, -1, 1, -1}; // 대각선 방향

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> r >> c;
    // Convert from 1-based to 0-based indexing
    r--; c--;
}

void move(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x;
        int ny = y;
        while (true) {
            nx += dx[i];
            ny += dy[i];
            // 체스판을 벗어나면 종료
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) break;
            // 이동 가능한 위치를 1로 설정
            arr[nx][ny] = 1;
            // 이동 도중 다른 기물이 있는 경우 종료
            if (arr[nx][ny] == 1) break;
        }
    }
    // 시작 위치도 1로 설정
    arr[x][y] = 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();

    // 비숍의 위치에서 이동 가능한 모든 위치를 마킹
    move(r, c);

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
