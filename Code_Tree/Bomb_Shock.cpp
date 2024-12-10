#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 0;
int bomb_type[20][20];  // 폭탄 종류를 저장하는 2차원 배열
bool bombed[20][20];    // 폭탄 피해 여부를 저장하는 2차원 배열
vector<pair<int, int>> bomb_pos;  // 폭탄 위치를 저장하는 벡터

// 폭탄의 영향을 주는 범위 정의
int bomb_shapes[4][5][2] = {
        {}, // 0번(사용되지 않음)
        {{-2, 0}, {-1, 0}, {0, 0}, {1, 0}, {2, 0}}, // 1번 폭탄
        {{-1, 0}, {1, 0}, {0, 0}, {0, -1}, {0, 1}}, // 2번 폭탄
        {{-1, -1}, {-1, 1}, {0, 0}, {1, -1}, {1, 1}} // 3번 폭탄
};

// 격자 범위 내에 있는지 확인하는 함수
bool in_range(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// 특정 위치에 폭탄 터뜨리기
void bomb(int x, int y, int b_type) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + bomb_shapes[b_type][i][0];
        int ny = y + bomb_shapes[b_type][i][1];
        if (in_range(nx, ny)) {
            bombed[nx][ny] = true;
        }
    }
}

// 폭탄을 터뜨리고 피해 영역 계산
int calc() {
    // bombed 배열 초기화
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bombed[i][j] = false;
        }
    }

    // bomb_type 배열에 따라 폭탄 터뜨리기
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (bomb_type[i][j]) {
                bomb(i, j, bomb_type[i][j]);
            }
        }
    }

    // 피해 영역 계산
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (bombed[i][j]) {
                cnt++;
            }
        }
    }

    return cnt;
}

// 최대 피해 영역 찾기
void find_max_area(int cnt) {
    if (cnt == bomb_pos.size()) {
        ans = max(ans, calc());
        return;
    }

    for (int i = 1; i <= 3; ++i) {
        int x = bomb_pos[cnt].first;
        int y = bomb_pos[cnt].second;

        bomb_type[x][y] = i;
        find_max_area(cnt + 1);
        bomb_type[x][y] = 0;
    }
}

int main() {
    cin >> n;

    // bomb_type 배열 초기화
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            bomb_type[i][j] = 0;
        }
    }

    // 입력 처리
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int bomb_place;
            cin >> bomb_place;
            if (bomb_place) {
                bomb_pos.push_back({i,j});
            }
        }
    }

    find_max_area(0);

    cout << ans << "\n";
    return 0;
}
