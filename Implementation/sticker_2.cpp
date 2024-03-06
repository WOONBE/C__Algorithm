
#include <iostream>
#include <istream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 
int n, m, k;
int r, c;
int book[40][40];
int sticker[12][12];

bool pastable(int x, int y) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (book[x + i][y + j] == 1 && sticker[i][j] == 1) //이미 붙인 공간에 붙이려고 시도할때
				return false;
		}


	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (sticker[i][j] == 1) { //빈 공간에 붙이려고 시도할때
				book[x + i][y + j] = 1;
			}
		}
	}
	return true;
}

void rotate() {

	int tmp[12][12];
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			tmp[i][j] = sticker[i][j]; //회전을 위하여 임시로 복사
		}
	}
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			sticker[i][j] = tmp[r - 1 - j][i]; //회전시킬때 안에 들어가는 값 변경되는거 제대로 확인하고 코드 작성(r,c 순서로 하면 당연히 값 이상함)
			
		}
	}swap(r, c);
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j];
		}
	}
		for (int rot = 0; rot < 4; rot++) {
			bool is_paste = false; // 해당 스티커를 붙였는가?
			for (int x = 0; x <= n - r; x++) { //시작점 설정 : ex 7에 5짜리 스티커를 붙이려면 시작점이 0,1,2
				if (is_paste) break;
				for (int y = 0; y <= m - c; y++) {
					if (pastable(x, y)) {
						is_paste = true;
						break;
					}
				}
			}
			if (is_paste) break;
			rotate();
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += book[i][j];
	cout << cnt << '\n';

}
