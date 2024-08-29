#include <iostream>
#include <queue>
using namespace std;

#define MAX 101
int N, M, Q;
int board[MAX][MAX];
queue<pair<int, char>> q;

// 입력 함수
void input() {
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }
    for (int k = 0; k < Q; k++) {
        int row;
        char dir;
        cin >> row >> dir;
        q.push({row, dir});
    }
}

// 한 칸 미는 함수
void push(int arr[], char dir) {
    if (dir == 'R') {
        int temp = arr[1];
        for (int i = 1; i < M; i++) {
            arr[i] = arr[i + 1];
        }
        arr[M] = temp;
    } else {
        int temp = arr[M];
        for (int i = M; i > 1; i--) {
            arr[i] = arr[i - 1];
        }
        arr[1] = temp;
    }
}

// 열 체크 함수
bool check(int row1, int row2) {
    for (int j = 1; j <= M; j++) {
        if (board[row1][j] == board[row2][j]) {
            return true;
        }
    }
    return false;
}

// 전파 함수
void spread(int startRow, char initialDir) {
    // 위쪽으로 전파
    char currentDir = (initialDir == 'L') ? 'R' : 'L';
    for (int i = startRow - 1; i >= 1; i--) {
        if (check(i + 1, i)) {
            push(board[i], currentDir);
            currentDir = (currentDir == 'L') ? 'R' : 'L';
        } else {
            break;
        }
    }

    // 아래쪽으로 전파
    currentDir = (initialDir == 'L') ? 'R' : 'L';
    for (int i = startRow + 1; i <= N; i++) {
        if (check(i - 1, i)) {
            push(board[i], currentDir);
            currentDir = (currentDir == 'L') ? 'R' : 'L';
        } else {
            break;
        }
    }
}

// 바람 처리 함수
void wind() {
    while (!q.empty()) {
        auto start = q.front(); q.pop();
        int startRow = start.first;
        char direction = start.second;
        push(board[startRow], direction);
        spread(startRow, direction);
    }
}

// 출력 함수
void output() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    wind();
    output();
    return 0;
}
