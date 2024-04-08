
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100
using namespace std;

int T, N, M, K;
int ans;

struct Micro {
	int x;
	int y;
	int num;
	int dir;
};

vector<Micro> Mi;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };


void Init() {
	Mi.clear();
	ans = 0;

}
void Input() {
	cin >> N >> M >> K;
	int x, y, n, d;
	for (int i = 0; i < K; i++) {
		cin >> x >> y >> n >> d;
		Mi.push_back({ x,y,n,d });


	}
}
int change_dir(int dir) {
	if (dir == 1)
		return 2;
	if (dir == 2)
		return 1;
	if (dir == 3)
		return 4;
	if (dir == 4)
		return 3;
}


bool cmp(Micro a, Micro b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;

	}
}
void Move_Micro() {
	int x, y, n, d;
	int nx, ny;

	vector<Micro> tmp;
	for (int i = 0; i < Mi.size(); i++) {
		x = Mi[i].x;
		y = Mi[i].y;
		n = Mi[i].num;
		d = Mi[i].dir;

		nx = x + dx[d]; //여기 헷갈릴뻔
		ny = y + dy[d];

		if (nx == 0 || ny == 0 || nx == N - 1 || ny == N - 1) { //경계선이면 회전되게 + 여기 오타
			x = nx;
			y = ny;
			n = Mi[i].num /= 2;
			d = change_dir(d);

			if (Mi[i].num == 0)
				continue;
			else {
				tmp.push_back({ x,y,n,d });
			}

		}
		else {
			x = nx;
			y = ny;
			tmp.push_back({ x,y,n,d });
		}
	}

	Mi.clear();
	sort(tmp.begin(), tmp.end(), cmp);

	for (int i = 0; i < tmp.size(); i++) {
		x = tmp[i].x;
		y = tmp[i].y;
		int sum = tmp[i].num;
		int mxNum = tmp[i].num, mxdir = tmp[i].dir;

		int j;
		for (j = i + 1; j < tmp.size(); j++) {
			if (tmp[j].x != x || tmp[j].y != y) break;
			if (tmp[j].x == x && tmp[j].y == y) {
				sum += tmp[j].num;
				if (mxNum < tmp[j].num) {
					mxNum = tmp[j].num;
					mxdir = tmp[j].dir;
				}
			}
		}
		i = j - 1;
		Mi.push_back({ x,y,sum,mxdir });
	}
}

void Solve() {
	for (int i = 0; i < M; i++) {
		Move_Micro();
	}

	for (int i = 0; i < Mi.size(); i++)
		ans += Mi[i].num;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		Init();
		Input();
		Solve();
		cout << '#' << tc << ' ' << ans << "\n";
	}
	return 0;

}
