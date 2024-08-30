#include <iostream>
#include <vector>
using namespace std;

#define MAX 101

int N;
int arr[MAX][MAX];
int startX, startY;
int firstLen, secondLen, thirdLen, fourthLen;
int dir;

void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    cin >> startX >> startY >> firstLen >> secondLen >> thirdLen >> fourthLen >> dir;
}

void output() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << "\n";
    }
}

// 경로 Find
vector<int> getRectangle(int r, int c, int m1, int m2, int m3, int m4) {
    vector<int> path;
    int x = r, y = c;

    // 1번 방향
    for (int i = 0; i < m1; i++) {
        path.push_back(arr[x][y]);
        x--;
        y++;
    }
    // 2번 방향
    for (int i = 0; i < m2; i++) {
        path.push_back(arr[x][y]);
        x--;
        y--;
    }
    // 3번 방향
    for (int i = 0; i < m3; i++) {
        path.push_back(arr[x][y]);
        x++;
        y--;
    }
    // 4번 방향
    for (int i = 0; i < m4; i++) {
        path.push_back(arr[x][y]);
        x++;
        y++;

    }

    return path;
}

// 회전
void rotateRectangle(vector<int>& path, bool clockwise) {
    int len = path.size();
    if (!clockwise) {
        int last = path[len - 1];
        for (int i = len - 1; i > 0; i--) {
            path[i] = path[i - 1];
        }
        path[0] = last;
    } else {
        int first = path[0];
        for (int i = 0; i < len - 1; i++) {
            path[i] = path[i + 1];
        }
        path[len - 1] = first;
    }
}

// 기울어진 직사각형의 회전 결과를 배열에 반영하는 함수
void applyRotation(const vector<int>& path, int r, int c, int m1, int m2, int m3, int m4) {
    int x = r, y = c;
    int idx = 0;

    // 1번 방향
    for (int i = 0; i < m1; i++) {
        arr[x][y] = path[idx++];
        x--;
        y++;
    }
    // 2번 방향
    for (int i = 0; i < m2; i++) {
        arr[x][y] = path[idx++];
        x--;
        y--;
    }
    // 3번 방향
    for (int i = 0; i < m3; i++) {
        arr[x][y] = path[idx++];
        x++;
        y--;
    }
    // 4번 방향
    for (int i = 0; i < m4; i++) {
        arr[x][y] = path[idx++];
        x++;
        y++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();

    // 기울어진 직사각형의 경로를 구하고 회전
    vector<int> rectangle = getRectangle(startX, startY, firstLen, secondLen, thirdLen, fourthLen);
    rotateRectangle(rectangle, dir == 1);
    applyRotation(rectangle, startX, startY, firstLen, secondLen, thirdLen, fourthLen);

    output();
    return 0;
}

