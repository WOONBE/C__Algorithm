#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> arr;
vector<vector<int>> psum;

void input() {
    cin >> n >> m;
    arr.resize(n + 1, vector<int>(m + 1));
    psum.resize(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            psum[i][j] = arr[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
        }
    }
}

//void computePrefixSum() {
//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= m; j++) {
//            psum[i][j] = arr[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
//        }
//    }
//}

int gridSum(int x1, int y1, int x2, int y2) {
    int ret = psum[x2][y2];
    if (x1 > 1) ret -= psum[x1 - 1][y2];
    if (y1 > 1) ret -= psum[x2][y1 - 1];
    if (x1 > 1 && y1 > 1) ret += psum[x1 - 1][y1 - 1];
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
//    computePrefixSum();

    cin >> k;
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << gridSum(x1, y1, x2, y2) << '\n';
    }

    return 0;
}
