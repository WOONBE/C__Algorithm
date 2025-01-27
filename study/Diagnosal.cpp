#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int N, M, x, y, clr;
    string color;
    cin >> N >> M;

    vector<vector<int>> point(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> color;
        if (color == "W") clr = 0;
        else clr = 1;
        point[i] = {x, y, clr};
    }

    sort(point.begin(), point.end());

    int min_Y = 2 * N; // 초기값 설정
    bool Ans = true;

    for (int i = 0; i < M; i++) {
        int y1 = point[i][1];
        if (point[i][2] == 0) {
            min_Y = min(min_Y, y1);
        }
        if (point[i][2] == 1) {
            if (min_Y <= y1) {
                Ans = false;
                break;
            }
        }
    }

    if (Ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
