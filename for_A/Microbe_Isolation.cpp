//
// Created by 김헌우 on 2024/04/07.
//
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100
using namespace std;

int T, N, M, K;

struct Mi {
    int x;
    int y;
    int num;
    int dir;
};
//vector <pair<int,int>> Map[MAX][MAX];
vector <Mi> mi;
int res;

int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };

/*void print(vector<Mi> tmp) {
    for (int i = 0; i < tmp.size(); i++) {
        cout << tmp[i].x << tmp[i].y<< tmp[i].num << tmp[i].dir << endl;
    }
}*/

void Init() {
    mi.clear();
    res = 0;
}
void Input() {
    cin >> N >> M >> K;

    int x, y, n, d;
    for (int i = 0; i < K; i++) {
        cin >> x >> y >> n >> d;
        mi.push_back({ x,y,n,d });
        //Map[x][y].push_back({ n,d });
    }
}

int change_dir(int dir) {
    if (dir == 1) return 2;
    if (dir == 2) return 1;
    if (dir == 4) return 3;
    if (dir == 3) return 4;
}

bool cmp(Mi a, Mi b) {
    if (a.x == b.x)
        return a.y < b.y;
    else
        return a.x < b.x;

}

void move_mi() {
    int x, y, n, dir;
    int nx, ny;

    //vector<pair<int, int>> tmp[MAX][MAX];
    vector<Mi> tmp;

    for (int i = 0; i < mi.size(); i++) {
        x = mi[i].x;
        y = mi[i].y;
        n = mi[i].num;
        dir = mi[i].dir;

        nx = x + dx[dir];
        ny = y + dy[dir];
        if (nx == 0 || nx == N - 1 || ny == 0 || ny == N - 1) {
            mi[i].x = nx;
            mi[i].y = ny;
            mi[i].num /= 2;
            mi[i].dir = change_dir(dir);

            if (mi[i].num == 0) continue;
            else tmp.push_back({nx, ny, mi[i].num ,mi[i].dir });
        }
        else {
            mi[i].x = nx;
            mi[i].y = ny;
            tmp.push_back({nx,ny, mi[i].num ,mi[i].dir });
        }
    }
    mi.clear();
    sort(tmp.begin(), tmp.end(), cmp);
//    print(tmp);
    //군집 1마리 이상인 것들 합쳐주기
    for (int i = 0; i < tmp.size(); i++) {
        x = tmp[i].x;
        y = tmp[i].y;
        int sum = tmp[i].num;
        int maxn = tmp[i].num, maxd = tmp[i].dir;

        int j;
        for (j = i + 1; j < tmp.size(); j++) {
            if (tmp[j].x != x || tmp[j].y != y) break;
            if (tmp[j].x == x && tmp[j].y == y) {
                sum += tmp[j].num;
                if (maxn < tmp[j].num) {
                    maxn = tmp[j].num;
                    maxd = tmp[j].dir;
                }
            }
        }
        i = j - 1;
        mi.push_back({ x,y,sum,maxd });
    }

}

void Solve() {
    for (int i = 0; i < M; i++) {
        move_mi();
    }

    for (int i = 0; i < mi.size(); i++)
        res += mi[i].num;
}

int main() {
    cin >> T;
    for (int tk = 1; tk <= T; tk++) {
        Init();
        Input();
        Solve();

        cout << "#" << tk << " " << res << endl;
    }
    return 0;
}

