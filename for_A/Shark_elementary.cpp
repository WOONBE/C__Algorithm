#include <iostream>
using namespace std;

int N, num, seat[21][21], student[401][4];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isInLikeStudent(int cur, int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (student[cur][i] == seat[x][y])
            return true;
    }
    return false;
}

void sitDownOneByOne(int cur) {
    int resX = -1, resY = -1;
    //여기가 중요한 포인트! 0 / 0인 경우가 정답이 될 수 있다
    int maxLikeStudents = -1, maxEmpties = -1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int likeStudents = 0;
            int empty = 0;

            if (seat[i][j] > 0)
                continue;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx <= 0 || nx > N || ny <= 0 || ny > N)
                    continue;
                if (seat[nx][ny] == 0) {
                    empty++;
                } else if (isInLikeStudent(cur, nx, ny)) {
                    likeStudents++;
                }
            }

            if (likeStudents > maxLikeStudents) {
                maxLikeStudents = likeStudents;
                maxEmpties = empty;
                resX = i;
                resY = j;
            } else if (likeStudents == maxLikeStudents) {
                if (empty > maxEmpties) {
                    maxEmpties = empty;
                    resX = i;
                    resY = j;

                } else if (empty == maxEmpties) {
                    if (resX == i && resY > j) {
                        resY = j;
                    } else if (resX > i) {
                        resX = i;
                        resY = j;
                    }
                }
            }
        }
    }

    seat[resX][resY] = cur;
}

void Input() {
    cin >> N;
    num = N * N;
    for (int i = 1; i <= num; i++) {
        int cur;
        cin >> cur;
        for (int j = 0; j < 4; j++) {
            cin >> student[cur][j];
        }
        sitDownOneByOne(cur);
    }
}

int calAns() {
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {

            int myFriends = 0;
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx <= 0 || nx > N || ny <= 0 || ny > N)
                    continue;
                if (isInLikeStudent(seat[i][j], nx, ny)) {
                    myFriends++;
                }
            }
            if (myFriends == 1) {
                ans += 1;
            } else if (myFriends == 2) {
                ans += 10;
            } else if (myFriends == 3) {
                ans += 100;
            } else if (myFriends == 4) {
                ans += 1000;
            }
        }
    }

    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    Input();
    cout << calAns() << '\n';

    return 0;
}
