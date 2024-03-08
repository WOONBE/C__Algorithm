#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

int ans;
char arr[5][5]; //string으로 하면 값 이상함
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
unordered_set<string> s; //unordered_set하니까 시간 확줄어듬

void init() {
	ans = 0;
	s.clear();
}
void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}

}
void bfs(int x, int y, int cnt, string num ) {
	if (cnt == 7) {
		s.insert(num);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && 4 > nx && ny >= 0 && 4 > ny) {
			bfs(nx, ny, cnt + 1, num + (arr[nx][ny]));
		}
	}


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		for (int i = 0; i < 4; i++) {//이부분 단순 bfs(0,0,0,"")로 했다가 낭패(모든 경우 다돌림)
			for (int j = 0; j < 4; j++) {
				bfs(i, j, 0, "");
			}
		}
		cout << "#" << tc << ' ' << s.size() << "\n";
	}
}
