#include <vector>
#include <iostream>
#include <utility>
#include <limits>


using namespace std;
int n, m, h;
bool ladder_pos[31][11];
int ladder_cnt; // 가로선을 추가할 개수
bool flag = false;

void dfs(int y, int cnt) {
    if (ladder_cnt == cnt) {
        bool possible = true; // 각각의 세로선이 잘 도착했는지 여부체크
        for (int i = 1; i <= n; i++) { // 세로선
            int verti = i;
            for (int j = 0; j < h; j++) { // 가로선
                int hight = j;

                if (ladder_pos[hight][verti]) { // 오른쪽으로 가는 경우
                    verti++;
                }
                else if (verti > 1 && ladder_pos[hight][verti - 1]) {
                    //왼쪽으로 가는 경우
                    verti--;
                }
            }
            if (verti != i) { // 잘못된 세로선
                possible = false;
                break;
            }
        }
        if (possible) {
            flag = true; // 정답
        }
        return;
    }

    // 가로선 추가하는 코드
    for (int i = y; i < h; i++) {
        for (int j = 1; j < n; j++) {
            if (!ladder_pos[i][j - 1] && !ladder_pos[i][j] && !ladder_pos[i][j + 1]) {
                //사다리가 추가 될 수 있는 위치인지 확인
                ladder_pos[i][j] = true; // 사다리 추가
                dfs(i, cnt + 1); // y좌표와 사다리 추가 개수 카운트
                ladder_pos[i][j] = false; // 추가한 사다리 삭제
            }
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> h;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ladder_pos[a - 1][b] = true; //문제에서 준 가로선 표시
    }

    for (int i = 0; i <= 3; i++) { // 가로선 추가 개수마다 확인
        ladder_cnt = i;
        dfs(0, 0);
        if (flag) { // 정답을 찾은 경우
            cout << ladder_cnt << endl;
            return 0;
        }
    }

    cout << -1 << endl; // 정답을 찾지 못한 경우
    return 0;
}
