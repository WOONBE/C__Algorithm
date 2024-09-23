#include <bits/stdc++.h>
using namespace std;

int n, m;
string s[11];
int d[11][11][11][11];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int ox, oy;
struct A {
    int bx, by, rx, ry;
};

queue<A> q;

pair<int, int> moveEnd(int x, int y, int dir) {
    int nx = x + dx[dir], ny = y + dy[dir];
    while (true) {
        if (s[nx][ny] == 'O')return { nx,ny };
        if (s[nx][ny] != '.')return { nx - dx[dir], ny - dy[dir] };
        nx += dx[dir];
        ny += dy[dir];
    }
}

void bfs() {
    while (!q.empty()) {
        A now = q.front();
        q.pop();
        if (d[now.bx][now.by][now.rx][now.ry] > 10) {
            cout << -1 <<'\n';
            exit(0);
        }
        for (int i = 0; i < 4; i++) {
            s[now.bx][now.by] = 'B';
            s[now.rx][now.ry] = 'R';
            pair<int, int> bl, re;
            bool flag = false;
            //rmove
            s[now.rx][now.ry] = '.';
            re = moveEnd(now.rx, now.ry, i);
            if (s[re.first][re.second] == 'O')flag = true;
            if (!flag)s[re.first][re.second] = 'R';
            //bmove
            s[now.bx][now.by] = '.';
            bl = moveEnd(now.bx, now.by, i);
            if (s[bl.first][bl.second] == 'O') {
                if (!flag) {
                    s[re.first][re.second] = '.';
                }
                continue;
            }
            s[bl.first][bl.second] = 'B';
            //rmove
            if (!flag) {
                s[re.first][re.second] = '.';
                re = moveEnd(re.first, re.second, i);
                if (s[re.first][re.second] == 'O')flag = true;
                if (!flag)s[re.first][re.second] = 'R';
            }
            //bmove
            s[bl.first][bl.second] = '.';
            bl = moveEnd(bl.first, bl.second, i);
            if (s[bl.first][bl.second] == 'O') {
                if (!flag) {
                    s[re.first][re.second] = '.';
                }
                continue;
            }
            s[bl.first][bl.second] = 'B';

            if (flag) {
                cout << d[now.bx][now.by][now.rx][now.ry] << '\n';
                exit(0);
            }
            s[bl.first][bl.second] = s[re.first][re.second] = '.';
            if (d[bl.first][bl.second][re.first][re.second] == 0) {
                d[bl.first][bl.second][re.first][re.second] = d[now.bx][now.by][now.rx][now.ry] + 1;
                q.push({ bl.first,bl.second,re.first,re.second });
            }
        }
    }
    cout << -1 << '\n';
    exit(0);
}



int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    int nbx, nby, nrx, nry;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'B') {
                nbx = i;
                nby = j;
            }
            if (s[i][j] == 'R') {
                nrx = i;
                nry = j;
            }
        }
    }
    s[nbx][nby] = s[nrx][nry] = '.';
    d[nbx][nby][nrx][nry] = 1;
    q.push({ nbx,nby,nrx,nry });
    bfs();
}