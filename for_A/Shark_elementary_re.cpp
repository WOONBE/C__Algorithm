// 범위 밖 조건 줄때 or로 안줘서 값 이상하게 나왔음


#include <iostream>
#include <algorithm>

int seat[21][21];
int student[401][4];
int n,ans;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
using namespace std;

void init() {
	ans = 0;
	
}

bool isLike(int cur, int x, int y) {
	for (int i = 0; i < 4; i++) {
		if (student[cur][i] == seat[x][y]) {
			return true;
		}
	}
	return false;
}

void sitDown(int cur) {
	int resX = -1, resY = -1;
	
	int maxLikeStudents = -1, maxEmpties = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int likeStudent = 0;
			int empty = 0;
			if (seat[i][j] > 0) continue;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
				if (seat[nx][ny] == 0) empty++;
				else if (isLike(cur, nx, ny)) likeStudent++;

			}
			if (likeStudent > maxLikeStudents) {
				maxLikeStudents = likeStudent;
				maxEmpties = empty;
				resX = i;
				resY = j;
			}
			else if (likeStudent == maxLikeStudents) {
				if (empty > maxEmpties) {
					maxEmpties = empty;
					resX = i;
					resY = j;

				}
				else if (empty == maxEmpties) {
					if (resX == i && resY > j) {
						resY = j;
					}
					else if (resX > i) {
						resX = i;
						resY = j;
					}
				}
			}
			
		}
	}
	seat[resX][resY] = cur;
}


void input() {
	cin >> n;
	int num = n * n;
	for (int i = 1; i <= num; i++) {
		int cur;
		cin >> cur;
		for (int j = 0; j < 4; j++) {
			cin >> student[cur][j];

		}
		sitDown(cur);
	}
}

int solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int friends = 0;
			for (int dir = 0; dir < 4; dir++) {
				int nx = i + dx[dir];
				int ny = j + dy[dir];
				if (nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
				if (isLike(seat[i][j], nx, ny)) friends++;
			}
			if (friends == 0) {
				ans += 0;
			}

			else if (friends == 1) {
				ans += 1;
			}
			else if (friends == 2) {
				ans += 10;
			}
			else if (friends == 3) {
				ans += 100;
			}
			else if (friends == 4) {
				ans += 1000;
			}
			
		}
	}
	return ans;
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	init();
	input();
	int result = solve();

    for(int i=0; i<n ; i++){
        for(int j=0; j<n; j++){
            cout << seat[i][j] << ' ';
        }
        cout << "\n";
    }

	cout << result << "\n";
	return 0;


}
