#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;


int n, m, k;
int arr[350][350];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Cell {
	int x;
	int y;
	int life;
	int restLife;
};

struct cmp {
	bool operator()(Cell a, Cell b) {
		return a.life <  b.life;
	}
};

vector<Cell> cells;

void init() {
	memset(arr, 0, sizeof(arr));
	cells.clear();
}

void input() {
	cin >> n >> m >> k;
	int cellLife;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> cellLife;
			arr[150 + i][150 + j] = cellLife;
			if (cellLife != 0) {
				cells.push_back({ 150 + i, 150 + j, cellLife, cellLife });
			}

		}
	}
}

int solve() { //이 함수 다시 확인
	priority_queue<Cell, vector<Cell>, cmp> activation;
	int dead = 0, nx = 0, ny = 0;
	Cell now;
	while (k > 0) {
		k--;
		for (int i = 0; i < cells.size(); i++) {
			cells[i].restLife--;
			if (cells[i].restLife == -1) {
				activation.push(cells[i]);
			}
			if (cells[i].restLife == -cells[i].life) {
				dead++;
			}
		}
		while (!activation.empty()) {
			now = activation.top();
			activation.pop();
			for (int i = 0; i < 4; i++) {
				nx = now.x + dx[i];
				ny = now.y + dy[i];
				if (arr[nx][ny] == 0) {
					arr[nx][ny] = now.life;
					cells.push_back({ nx,ny,now.life, now.life }); //여기 둘다 life로 in
				}
			}

		}
	}
	return cells.size() - dead;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		int ret = solve();
		cout << '#' << tc << ' ' << ret << "\n";
	}
	return 0;
}
