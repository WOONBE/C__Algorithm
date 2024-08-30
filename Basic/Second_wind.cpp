#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 101

int arr[MAX][MAX];
int N, M, Q;
int startX, startY, endX, endY;

queue<pair<int, int>> q;

int dx[4] = {1, 0, -1, 0}; // 하, 우, 상, 좌
int dy[4] = {0, 1, 0, -1}; // 하, 우, 상, 좌

// 반시계 방향 회전
void spin(int x1, int y1, int x2, int y2) {
    int temp1,temp2,temp3;

    // 왼쪽에서 오른쪽으로
    temp1 = arr[x1][y2];
    for (int i = y2; i > y1; i--) {
        arr[x1][i] = arr[x1][i - 1];
    }
    // 위에서 아래로
    temp2 = arr[x2][y2];
    for (int i = x2; i > x1; i--) {
        arr[i][y2] = arr[i - 1][y2];
    }
    arr[x1+1][y2] = temp1;

    //오른쪽에서 왼쪽으로(정상)
    temp3 = arr[x2][y1];
    for (int i = y1; i < y2; i++) {
        arr[x2][i] = arr[x2][i+1];
    }
    arr[x2][y2-1] = temp2;

    //아래쪽에서 위쪽으로(정상)
    for (int i = x1; i < x2; i++) {
        arr[i][y1] = arr[i+1][y1];
    }
    arr[x2-1][y1] = temp3;
}


// 평균값 나눈걸로 숫자 설정
void setNumber(int x1, int y1, int x2, int y2) {
    vector<vector<int>> temp(N + 1, vector<int>(M + 1, 0)); // 변경된 값을 임시 저장할 배열

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            int sum = arr[i][j];
            int count = 1;

            // 상하좌우 확인
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                // 경계 내에 있는지 확인(외곽이거나 숫자가 없는 경우 고려)
                if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                    sum += arr[nx][ny];
                    count++;
                }
            }

            temp[i][j] = sum / count;
        }
    }

    // 임시 배열의 값을 원래 배열로 복사
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

// 바람 처리
void wind() {
    while (!q.empty()) {
        auto start = q.front(); q.pop();
        startX = start.first;
        startY = start.second;
        auto end = q.front(); q.pop();
        endX = end.first;
        endY = end.second;

        spin(startX, startY, endX, endY); // 경계 회전
        setNumber(startX, startY, endX, endY); // 숫자 변경
    }
}

// 입력
void input() {
    cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    while (Q--) {
        cin >> startX >> startY >> endX >> endY;
        q.push({startX, startY});
        q.push({endX, endY});
    }
}

// 출력
void output() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << ' ';
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
