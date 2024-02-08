
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stack>


#define X first
#define Y second
using namespace std;


int board[51][51]; //배추 위치 in
bool vis[51][51]; //방문여부

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, k;
queue<pair<int, int>> Q;

void bfs(int x, int y) {
	vis[x][y] = true;
	Q.push({ x,y });
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (vis[nx][ny] || board[nx][ny] != 1) continue;
			vis[nx][ny] = true;
			Q.push({ nx,ny });
		}
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;

	while (t--) {
		cin >> m >> n >> k; //n,m으로 나타남
		int x, y;
		for(int i=0; i<k; i++){ //여기서 i++가 아니라 k++로 오타나서 오류떴음
			cin >> x >> y;
			board[y][x] = 1;

		}
		//시작점 찾고 bfs 돌리기
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1 && !vis[i][j]) {
					bfs(i,j);
					num++;
				}
			}
		}
		cout << num << "\n";

		for (int i = 0; i < n; i++) {
			fill(board[i], board[i] + m, 0);  //초기화 시키고 한번 더 실행
			fill(vis[i], vis[i] + m, false);
		}
	}return 0;

}

	
    



