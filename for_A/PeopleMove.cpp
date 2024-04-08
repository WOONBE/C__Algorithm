#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;
#define X first
#define Y second

int n, l, r;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int board[105][105];
int vis[105][105];
int ans;

void Init() {
	ans = 0;
	

}

void Input() {
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j];


}
void Solve() {
	while (true) {
		bool flg = false;
		for (int i = 0; i < 105; i++) fill(vis[i], vis[i] + 105, 0); //반드시 여기서 초기화
		queue<pair<int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!vis[i][j])
					q.push({ i,j });
				int sum = 0;
				vector<pair<int, int>> tmp;

				while (!q.empty()) {
					auto cur = q.front();
					q.pop();
					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.X + dx[dir];
						int ny = cur.Y + dy[dir];
						if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
						int diff = abs(board[cur.X][cur.Y] - board[nx][ny]);

						if (diff >= l && diff <= r) { //국경선 오픈
							flg = true;
							if (!vis[cur.X][cur.Y]) {
								tmp.push_back({ cur.X, cur.Y });
								sum += board[cur.X][cur.Y];
								vis[cur.X][cur.Y] = 1;
							}
							if (!vis[nx][ny]) {
								tmp.push_back({ nx, ny });
								sum += board[nx][ny];
								vis[nx][ny] = 1;
								q.push({ nx,ny });
							}
						}
					}
				}
				for (int k = 0; k < tmp.size(); k++) {
					board[tmp[k].X][tmp[k].Y] = sum / tmp.size();
				}
			}
			
		}
		if (!flg) break;
		ans++;
	}
	cout << ans;
}

int main() {
	Init();
	Input();
	Solve();
}
