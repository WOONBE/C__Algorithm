
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

#define X first
#define Y second
using namespace std;

string board[1002];
int fire[1002][1002]; //불
int jihoon[1002][1002]; //지훈이

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		fill(fire[i], fire[i] + m, -1);
		fill(jihoon[i], jihoon[i] + m, -1);

	}
	for (int i = 0; i < n; i++) {
		cin >> board[i];
	}
	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i,j });
				fire[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				jihoon[i][j] = 0;
			}
			
		}
	}

	while (!Q1.empty()) {
		auto cur = Q1.front();
		Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (fire[nx][ny] >= 0 || board[nx][ny] =='#') continue;
			
			fire[nx][ny] = fire[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}
	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) { //가장자리 도착시 탈출
				cout << jihoon[cur.X][cur.Y] + 1;
				return 0;
			}
			if (jihoon[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			// 불의 전파시간 조건 추가
			if (fire[nx][ny] <= jihoon[cur.X][cur.Y] + 1 && fire[nx][ny] != -1) continue;

			jihoon[nx][ny] = jihoon[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE"; //탈출 실패



    
}


