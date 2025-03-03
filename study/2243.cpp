#include <iostream>
#include <map>

using namespace std;

#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    FAST_IO

    int N, a, b, c;
    cin >> N;

    // 사탕의 맛을 기준으로 개수를 저장하는 map (key: 맛, value: 개수)
    map<int, int> candyBox;

    while (N--) {
        cin >> a;
        if (a == 1) {
            cin >> b;
            // b번째로 맛있는 사탕 찾기
            int cnt = 0;
            for (auto it = candyBox.begin(); it != candyBox.end(); it++) {
                cnt += it->second; // 해당 맛의 개수를 추가
                if (cnt >= b) {
                    cout << it->first << "\n"; // b번째 맛있는 사탕 출력
                    if (--it->second == 0) {
                        candyBox.erase(it); // 개수가 0이면 제거
                    }
                    break;
                }
            }
        } else if (a == 2) {
            cin >> b >> c;
            if (c > 0) {
                candyBox[b] += c; // 특정 맛의 사탕을 추가
            } else {
                candyBox[b] += c; // 특정 맛의 사탕을 제거
                if (candyBox[b] <= 0) {
                    candyBox.erase(b); // 개수가 0 이하가 되면 삭제
                }
            }
        }
    }

    return 0;
}
