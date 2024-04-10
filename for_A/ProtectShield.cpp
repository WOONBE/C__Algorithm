#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#define MAX INT_MAX
using namespace std;

// 두께(높이) D, 가로 길이 W, 합격기준 K
int T, D, W, K;
int film[14][21];
int ans;
int cnt_medi;
// 약품 선택 기록 저장
vector<int>path;

void init() {
    memset(film, 0, sizeof(film));
    ans = MAX;
    path.clear();
    cnt_medi = 0;
}

void input() {
    cin >> D >> W >> K;
    for (int y = 0; y < D; y++) {
        for (int x = 0; x < W; x++) {
            cin >> film[y][x];
        }
    }
}



// 지금 약물을 선택한대로 검사를 통과할 수 있는가 판단
bool check_sucess() {

    // 세로 선 하나 선택
    for (int x = 0; x < W; x++) {

        int cont = 1; // 지금까지 연속한 개수
        int prev = film[0][x]; // 맨위의 값
        int contMax = 1; // 연속한 개수의 최대값

        // 맨 위에 있는 약품 종류 적용
        if (path[0] != -1) {
            prev = path[0];
        }


        // 연속하는 약품 종류의 최대값 구하기
        for (int y = 1; y < D; y++) {

            // 현재 약품 종류
            int nowValue = film[y][x];

            // 약품 투입한 경우 적용
            if (path[y] != -1) {
                nowValue = path[y];
            }

            if (prev == nowValue) {
                cont++;
            }
            else {
                cont = 1;
            }
            prev = nowValue;
            contMax = max(contMax, cont);
        }
        if (contMax < K) return false; // 불합격
    }
    return true; // 합격
}

// 현재 층에서 x, A, B 중 1개를 고르고 다음 층으로 이동(-1, 0, 1)
void func(int now) {


    // 0~D-1층 까지 선택 완료
    if (now == D) {
        if (check_sucess()) {
            ans = min(ans, cnt_medi);
        }
        return;
    }

    // -1 : 약품 선택 x
    // 0 : 약품 A 선택
    // 1 : 약품 B 선택
    for (int i = -1; i <= 1; i++) {

        // 중요!! 가지치기 없으면 시간 제한 발생
        // 꼭 제외할 수 있는 조건 있으면 가지치기 해주기!

        // 합격 기준보다 높으면 굳이 더 이상 추가할 필요 없다.
        // -> K=3인 경우, cnt_medi가 4라면?
        // AAA 3개만 써도 충분히 최소값을 구할 수 있기 떄문!
        if (i != -1 && (cnt_medi + 1 > K))continue;


        // 이미 구한 최소값보다 현재 약품 선택 수가 더 크다면?
        // 굳이 고려할 필요 없으니 진행 x
        if (i != -1 && (cnt_medi + 1 >= ans))continue;

        path.push_back(i);

        // 약품을 사용하는 경우 cnt_medi ++
        if (i != -1)cnt_medi++;


        func(now + 1);

        // 재귀를 빠져나와 꺼내기 때문에 cnt_mdei --
        if (i != -1)cnt_medi--;
        path.pop_back();
    }

}

int main() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        init();
        input();
        func(0);
        cout << "#" << i << " " << ans << "\n";
    }

    return 0;
}