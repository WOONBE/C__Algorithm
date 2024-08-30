#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[21][21];

bool isPositiveRectangle(int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            if (arr[i][j] <= 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int maxArea = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = i; k < n; k++) {
                for (int l = j; l < m; l++) {
                    if (isPositiveRectangle(i, j, k, l)) {
                        int area = (k - i + 1) * (l - j + 1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }
    }

    cout << maxArea << "\n";

    return 0;
}
