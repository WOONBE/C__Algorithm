#include <iostream>
#include <algorithm>

using namespace std;

int n;
int input[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int maxHeight = 0;
    int maxIdx = 0;

    for (int i = 0; i < n; i++) {
        int idx, height;
        cin >> idx >> height;
        input[idx] = height;
        if (height > maxHeight) {
            maxHeight = height;
            maxIdx = idx;
        }
    }

    int answer = 0;
    int leftHeight = 0;

    // 왼쪽부터 최대 높이까지 계산
    for (int i = 1; i <= maxIdx; i++) {
        if (input[i] > leftHeight) {
            leftHeight = input[i];
        }
        answer += leftHeight;
    }

    int rightHeight = 0;

    // 오른쪽부터 최대 높이까지 계산
    for (int i = 1000; i > maxIdx; i--) {
        if (input[i] > rightHeight) {
            rightHeight = input[i];
        }
        answer += rightHeight;
    }

    cout << answer << "\n";

    return 0;
}
