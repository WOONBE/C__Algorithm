#include <iostream>
#include <string>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int T;

int untie(const string& C) {
    int n = C.length();
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (C[i] != C[(i+n-1)%n]) { // 이전 사람과 다른 지점 찾기
            start = i;
            break;
        }
    }
    if (start == -1) {
        return (n+1)/2; // 모두 같은 문자
    }

    int result = 0;
    int length = 0;
    for (int j = start; j < start + n; j++) {
        length++;
        if (C[j%n] != C[(j+1)%n]) { // 다음 사람과 다르면 그룹 끝
            result += length/2;
            length = 0;
        }
    }
    return result;
}

int main() {
    First
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string C;
        cin >> C;
        cout << "Case #" << t << ": " << untie(C) << "\n";
    }
}
