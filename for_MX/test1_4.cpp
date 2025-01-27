#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define MAX_N 1000
#define MAX_M 20

struct Result {
    int y, x;
};

static int N, M;
static int map[MAX_N][MAX_N];
static int piecePositions[MAX_M * MAX_M][2];
static int pieceCount;

// 비트맵으로 변환
void init(int n, int m, int (*Map)[MAX_N]) {
    N = n;
    M = m;
    memset(map, 0, sizeof(map)); // 초기화

    // 비트맵으로 변환
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (Map[i][j] == 1) {
                map[i][j] = 1;  // 해당 위치에 1 설정
            }
        }
    }
}

// 조각의 비트맵 변환
void extractPiecePositions(int (*Pieces)[MAX_M]) {
    pieceCount = 0;
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
            if (Pieces[y][x] == 1 || Pieces[y][x] == 9) {
                piecePositions[pieceCount][0] = y;
                piecePositions[pieceCount][1] = x;
                pieceCount++;
            }
        }
    }
}

// 회전 함수 (비트맵에서의 회전)
void rotate(int (*mat)[MAX_M]) {
    int tmp[MAX_M][MAX_M];
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
            tmp[x][M - y - 1] = mat[y][x];
        }
    }
    memcpy(mat, tmp, sizeof(tmp));
}

// 보물 찾기 함수
Result findTreasureChest(int (*Pieces)[MAX_M]) {
    int rotated[MAX_M][MAX_M];
    memcpy(rotated, Pieces, sizeof(rotated)); // 초기 회전 상태 복사

    // 비트맵으로 조각 지도 변환
    int pieceMap[MAX_M][MAX_M] = {0};
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < M; x++) {
            if (rotated[y][x] == 1 || rotated[y][x] == 9) {
                pieceMap[y][x] = 1;
            }
        }
    }

    for (int r = 0; r < 4; r++) {
        extractPiecePositions(rotated);

        for (int i = 0; i <= N - M; i++) {
            for (int j = 0; j <= N - M; j++) {
                bool matched = true;
                int bitMask = 0;

                // 매칭 검사 (비트마스크를 사용하여 비교)
                for (int k = 0; k < pieceCount; k++) {
                    int y = i + piecePositions[k][0];
                    int x = j + piecePositions[k][1];
                    if (map[y][x] != 1) {
                        matched = false;
                        break;
                    }
                    bitMask |= (1 << (y * N + x));  // 비트마스크 업데이트
                }

                // 보물 좌표 반환
                if (matched) {
                    for (int k = 0; k < pieceCount; k++) {
                        int y = piecePositions[k][0];
                        int x = piecePositions[k][1];
                        if (rotated[y][x] == 9) {
                            return {i + y, j + x};
                        }
                    }
                }
            }
        }

        // 회전 수행
        rotate(rotated);
    }

    return {-1, -1}; // 보물 상자 찾지 못함
}

int main() {
    // 예시 맵과 조각 데이터
    int Map[MAX_N][MAX_N] = {
            {0, 0, 1, 0, 0},
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1}
    };

    int Pieces[MAX_M][MAX_M] = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 0, 9}  // 보물(9) 위치
    };

    init(5, 3, Map); // 맵 초기화
    Result res = findTreasureChest(Pieces); // 보물 찾기

    if (res.y != -1) {
        cout << "Treasure found at (" << res.y << ", " << res.x << ")\n";
    } else {
        cout << "Treasure not found\n";
    }

    return 0;
}
