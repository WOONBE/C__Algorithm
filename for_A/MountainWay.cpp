#include <iostream>
#include <algorithm>
using namespace std;
int num, result, dig;
int arr[8][8];
bool check[8][8];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int dfs(int y, int x, int height, bool digged) {
    check[y][x] = true;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < num && ny < num && !check[ny][nx]) {
            if (arr[ny][nx] < height) {
                cnt = max(cnt, dfs(ny, nx, arr[ny][nx], digged));
            }
            else {
                if (!digged && arr[ny][nx] - dig < height) {
                    cnt = max(cnt, dfs(ny, nx, height - 1, true));
                }
            }
        }
    }
    check[y][x] = false;
    return cnt + 1;
}

int main() {
    int test, maxi;
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> num >> dig;
        result = 0;
        maxi = 0;
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++) {
                cin >> arr[i][j];
                check[i][j] = false;
                maxi = max(maxi, arr[i][j]);
            }
        for (int i = 0; i < num; i++)
            for (int j = 0; j < num; j++) {
                if (arr[i][j] == maxi) {
                    int tmp = dfs(i, j, arr[i][j], false);
                    result = max(result, tmp);
                }
            }
        cout << "#" << t << " " << result << '\n';
    }

    return 0;
}
