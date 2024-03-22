#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define mx 22
#define X first
#define Y second



using namespace std;
int n,ans;
int sze=2, curx, cury,ate; //상어 크기, x,y 좌표, 먹은 횟수
int arr[22][22];
int vis[22][22];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void init() {
	ans = 0;

}
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}
void findShark() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 9) {
				curx = i;
				cury = j;
				arr[i][j] = 0;
			}
		}
	}
}
int bfs(){
	for (int i = 0; i < mx; i++) {
		for (int j = 0; j < mx; j++) {
			vis[i][j] = 0;
		}
	}
	int dist = 0;
	queue<pair<int, int>> q;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	q.push({ curx,cury });
	vis[curx][cury] = 1;
	while (!q.empty()) {
		auto cur = q.front();
		q.pop();
		if (vis[cur.X][cur.Y] == dist) //이 코드 없으면 안돌아감
			break;
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (ny < 0 || nx < 0 || nx >= n || ny >= n)continue; //or로
			if (vis[nx][ny]) continue;
			if (!arr[nx][ny] || arr[nx][ny] == sze) {
				q.push({ nx,ny });
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			}
			else if (arr[nx][ny] < sze) {
				vis[nx][ny] = vis[cur.X][cur.Y] + 1;
				dist = vis[nx][ny];
				pq.push({ nx,ny });
			}
		}
	}
	if (pq.empty())
		return 0;
	curx = pq.top().X;
	cury = pq.top().Y;
	ate++;
	arr[curx][cury] = 0;
	if (ate == sze) {
		sze++;
		ate = 0;
	}
	return vis[curx][cury] - 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	init();
	input();
	findShark();
	while (1) {
		int sec = bfs();
		ans += sec;
		if (sec == 0) {
			break;
		}
	}
	cout << ans << "\n";
}
