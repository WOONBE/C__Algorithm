#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct info {
    int x, y;
};

info tmp;
vector<info> v;
int num, mxcon, ans;
int arr[12][12];


void init() {
    mxcon = 0;
    ans = 987654321;
    v.clear();
}

void input() {
    cin >> num;
    for (int i = 0; i < num; i++)
        for (int j = 0; j < num; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                //외곽지역은 안넣음
                if (i == 0 || i == num - 1 || j == 0 || j == num - 1) continue;
                tmp.x = i;
                tmp.y = j;
                v.push_back(tmp);
            }
        }
}
void dfs(int idx, int len, int conn) {
    if (idx == v.size()) {
        if (conn > mxcon) {
            ans = len;
            mxcon = conn;
        }
        else if (conn == mxcon)
            ans = min(ans, len);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nx = v[idx].x;
        int ny = v[idx].y;
        int cnt = 0;
        while (1) {
            nx += dx[i];
            ny += dy[i];
            cnt++;
            if (arr[nx][ny] == 1 || arr[nx][ny] == 2) {
                cnt = 0;
                break;
            }
            if (arr[nx][ny] == 0 && (nx == 0 || ny == 0 || nx == num - 1 || ny == num - 1)) {
                break;
            }
        }
        if (cnt > 0) {
            nx = v[idx].x;
            ny = v[idx].y;
            while (1) {
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || ny < 0 || nx > num - 1 || ny > num - 1)
                    break;
                arr[nx][ny] = 2;
            }
            dfs(idx + 1, len + cnt, conn + 1);
            nx = v[idx].x;
            ny = v[idx].y;
            while (1) {
                nx += dx[i];
                ny += dy[i];
                if (nx < 0 || ny < 0 || nx > num - 1 || ny > num - 1)
                    break;
                arr[nx][ny] = 0;
            }
        }
    }
    dfs(idx + 1, len, conn);
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        init();
        input();
        dfs(0, 0, 0);
        cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}