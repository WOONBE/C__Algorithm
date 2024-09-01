#include <iostream>
#include <string>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define FIRST cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 6
#define MAX_N 10005
#define LL long long
#define INF 1e9

using namespace std;
int N;
int Green_MAP[MAX][MAX];
int Blue_MAP[MAX][MAX];
int answer = 0;

// 블록이 초록색 보드로 떨어진다.
void Green_MAP_Falling(int T, int Y, int X) {
    if (T == 1) { // 1X1 블록은 그대로 떨어진다.
        int H = 0;
        while ((H <= 5) && (Green_MAP[H][X] == 0)) {
            H++;
        };
        H--;
        Green_MAP[H][X] = T;
    }
    else if (T == 2) { // 1X2 블록은 옆 열까지 비어있는지 확인해야 한다.
        int H = 0;
        while ((H <= 5) && (Green_MAP[H][X] == 0) && (Green_MAP[H][X + 1] == 0)) {
            H++;
        };
        H--;
        Green_MAP[H][X] = T;
        Green_MAP[H][X + 1] = T;
    }
    else if (T == 3) { // 2X1 블록은 밑 행까지 비어있는지 확인해야 한다.
        int H = 0;
        while ((H <= 4) && (Green_MAP[H][X] == 0) && (Green_MAP[H + 1][X] == 0)) {
            H++;
        };
        H--;
        Green_MAP[H][X] = T;
        Green_MAP[H + 1][X] = T;
    }
}

void Green_Full_Block() {
    for (int i = 5; i >= 2; i--) {
        bool isFull = true; // i행이 블록으로 가득 차 있으면 true, 아니면 false
        for (int j = 0; j <= 3; j++) {
            if (Green_MAP[i][j] == 0) { // 하나라도 비었다면 i행의 모든 블록을 제거하지 않는다.
                isFull = false;
                break;
            }
        }
        if (isFull) {
            answer++; // i행의 블록을 모두 제거했으므로, 점수를 1점 올린다.
            for (int j = 0; j <= 3; j++) { // i행의 블록을 모두 제거
                Green_MAP[i][j] = 0;
            }
            for (int j = (i - 1); j >= 0; j--) {
                for (int k = 0; k <= 3; k++) {
                    Green_MAP[j + 1][k] = Green_MAP[j][k];
                }
            }
            for (int j = 0; j <= 3; j++) {
                Green_MAP[0][j] = 0;
            }
            i++;
        }
    }
}

void Green_Delete_Row() {
    int Cnt = 0; // 제거할 행의 개수
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 3; j++) {
            if (Green_MAP[i][j] > 0) { // i행에 하나라도 블록이 있다면 제거할 행이 하나 늘어난다.
                Cnt++;
                break;
            }
        }
    }
    for (int i = (5 - Cnt); i >= 0; i--) {
        for (int j = 0; j <= 3; j++) {
            Green_MAP[i + Cnt][j] = Green_MAP[i][j];
        }
    }
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 3; j++) {
            Green_MAP[i][j] = 0;
        }
    }
}

int Green_Board_Size() {
    int res = 0;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 3; j++) {
            if (Green_MAP[i][j] != 0) {
                res++;
            }
        }
    }

    return res;
}

// 블록이 파란색 보드로 떨어진다.
void Blue_MAP_Falling(int T, int Y, int X) {
    // 1X1인 경우에는 그대로 떨어진다.
    if (T == 1) {
        int H = 0;
        while ((H <= 5) && (Blue_MAP[H][X] == 0)) {
            H++;
        };
        H--;
        Blue_MAP[H][X] = T;
    }
        // 2X1인 경우에는 4행까지 따져준다.
    else if (T == 2) {
        int H = 0;
        while ((H <= 4) && (Blue_MAP[H][X] == 0) && (Blue_MAP[H + 1][X] == 0)) {
            H++;
        };
        H--;
        Blue_MAP[H][X] = T;
        Blue_MAP[H + 1][X] = T;
    }
        // 1X2인 경우에는 다음 열까지 따져준다.
    else if (T == 3) {
        int H = 0;
        while ((H <= 5) && (Blue_MAP[H][X] == 0) && (Blue_MAP[H][X + 1] == 0)) {
            H++;
        };
        H--;
        Blue_MAP[H][X] = T;
        Blue_MAP[H][X + 1] = T;
    }
}

void Blue_Full_Block() {
    for (int i = 5; i >= 2; i--) {
        bool isFull = true; // i행이 블록으로 가득 차 있으면 true, 아니면 false
        for (int j = 0; j <= 3; j++) {
            if (Blue_MAP[i][j] == 0) { // 하나라도 비었다면 i행의 모든 블록을 제거하지 않는다.
                isFull = false;
                break;
            }
        }
        if (isFull) {
            answer++; // i행의 블록을 모두 제거했으므로, 점수를 1점 올린다.
            for (int j = 0; j <= 3; j++) { // i행의 블록을 모두 제거
                Blue_MAP[i][j] = 0;
            }
            for (int j = (i - 1); j >= 0; j--) {
                for (int k = 0; k <= 3; k++) {
                    Blue_MAP[j + 1][k] = Blue_MAP[j][k];
                }
            }
            for (int j = 0; j <= 3; j++) {
                Blue_MAP[0][j] = 0;
            }
            i++;
        }
    }
}

void Blue_Delete_Row() {
    int Cnt = 0; // 제거할 행의 개수
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 3; j++) {
            if (Blue_MAP[i][j] > 0) { // i행에 하나라도 블록이 있다면 제거할 행이 하나 늘어난다.
                Cnt++;
                break;
            }
        }
    }
    for (int i = (5 - Cnt); i >= 0; i--) {
        for (int j = 0; j <= 3; j++) {
            Blue_MAP[i + Cnt][j] = Blue_MAP[i][j];
        }
    }
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 3; j++) {
            Blue_MAP[i][j] = 0;
        }
    }
}

int Blue_Board_Size() {
    int res = 0;
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 3; j++) {
            if (Blue_MAP[i][j] != 0) {
                res++;
            }
        }
    }

    return res;
}

int main() {
    FIRST
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int T, Y, X;
        cin >> T >> Y >> X;
        Green_MAP_Falling(T, Y, X);
        Blue_MAP_Falling(T, X, Y);
        Green_Full_Block();
        Green_Delete_Row();
        Blue_Full_Block();
        Blue_Delete_Row();
    }
    cout << answer << "\n";
    cout << Green_Board_Size() + Blue_Board_Size() << "\n";

    return 0;
}