#include <iostream>
#include <algorithm>
using namespace std;

int n, m, x, y, k, dir;
int arr[21][21];
int dx[4] = {0,0,-1,1}; //동서남북
int dy[4] = {1,-1,0,0};
int dice[6] = {0,0,0,0,0,0};


bool OOB(int r, int c) {
    return r < 0 || r >= n || c < 0 || c >= m;
}

void input() {
    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
}

void move(int dir) {
    int tmp[6];
    copy(begin(dice), end(dice), begin(tmp));

    if (dir == 0) {  // 동
        dice[0] = tmp[3];
        dice[2] = tmp[0];
        dice[5] = tmp[2];
        dice[3] = tmp[5];
    }
    else if (dir == 1) {  // 서
        dice[0] = tmp[2];
        dice[2] = tmp[5];
        dice[5] = tmp[3];
        dice[3] = tmp[0];
    }
    else if (dir == 2) {  // 북
        dice[0] = tmp[4];
        dice[4] = tmp[5];
        dice[5] = tmp[1];
        dice[1] = tmp[0];
    }
    else if (dir == 3) {  // 남
        dice[0] = tmp[1];
        dice[4] = tmp[0];
        dice[5] = tmp[4];
        dice[1] = tmp[5];
    }

    x += dx[dir];
    y += dy[dir];
}
void setScore() {
    int dice_top = dice[0];
    int dice_bottom = dice[5];
    if (OOB(x, y)) {
        int cdir = (dir+2) %4;
        move(cdir);
        return;
    }
    if (arr[x][y] == 0) {
        arr[x][y] = dice_bottom;
    }
    else {
        dice[5] = arr[x][y];
        arr[x][y] = 0; //이부분 실수
    }
    cout << dice_top << '\n';
}


int main() {
    input();

    while (k--) {
        cin >> dir;
        //dirnum 기준으로 돌리기
        dir--;
        move(dir);
        setScore();
        /*if (OOB(x, y)) {
            continue;
        }
        else{
            cout << dice[0] << "\n";
        }*/
    }
}