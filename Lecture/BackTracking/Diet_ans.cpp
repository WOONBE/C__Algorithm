#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vector<int>> v; // 입력 받은 재료 데이터
vector<int> visited;   // 현재 탐색 중인 조합
vector<int> ans;       // 최종 선택된 최소 비용 조합
int n;

// 고려 사항: 최소 영양소 기준
int min_a, min_b, min_c, min_d;
int min_price = 987654321; // 큰 값으로 초기화

void dfs(int idx, int cnt, int a, int b, int c, int d, int price) {
    // 조건을 만족하는 경우
    if (cnt >= 1 && a >= min_a && b >= min_b && c >= min_c && d >= min_d) {
        if (price < min_price) {
            // 최소 비용을 갱신하는 경우
            min_price = price;
            ans.clear(); // 기존의 최적 조합을 삭제
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    ans.push_back(i + 1); // 1-based 인덱스 저장
                }
            }
        } else if (price == min_price) {
            vector<int> current;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    current.push_back(i + 1); // 1-based 인덱스 저장
                }
            }
            if (current < ans) {
                ans = current;
            }
        }
    }

    // 다음 인덱스로 이동하며 조합을 탐색
    for (int i = idx; i < n; i++) {
        if (visited[i]) continue; // 이미 선택된 재료는 건너뜀
        visited[i] = 1; // 선택 표시
        dfs(i + 1, cnt + 1, a + v[i][0], b + v[i][1], c + v[i][2], d + v[i][3], price + v[i][4]);
        visited[i] = 0; // 선택 해제
    }
}

// 입력 처리
void input() {
    cin >> n;
    v.resize(n, vector<int>(5));  // 재료의 정보 저장 (단백질, 지방, 탄수화물, 비타민, 가격)
    visited.resize(n, 0);         // 방문 여부 저장

    cin >> min_a >> min_b >> min_c >> min_d; // 최소 영양소 기준

    // 각 재료의 영양소와 가격 입력
    for (int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3] >> v[i][4];
    }
}

int main() {
    First;

    input();
    dfs(0, 0, 0, 0, 0, 0, 0); // DFS 탐색 시작

    if (min_price == 987654321) {
        cout << -1 << "\n";  // 조건을 만족하는 조합이 없는 경우
    } else {
        cout << min_price << "\n"; // 최소 비용 출력
        sort(ans.begin(), ans.end()); // 정답을 오름차순으로 정렬
        for (int i : ans) {
            cout << i << ' '; // 1-based index로 출력
        }
        cout << "\n";
    }

    return 0;
}
