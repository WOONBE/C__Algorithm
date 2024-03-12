#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,ans;
int food[20][20];
bool vis[20];


void init() {
	ans = 987654321;
	
}
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> food[i][j];
		}
	}
}

void recursion(int idx, int cnt) {
	if (cnt == n / 2) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i] && vis[j])
					a += food[i][j];
				else if (!vis[i] && !vis[j])
					b += food[i][j];
			}
		}
		ans = min(ans, abs(a - b));
		return;
	}
		if (idx >= n || ans == 0) {
			return;
		}
	vis[idx] = false;
	recursion(idx + 1, cnt);
	vis[idx] = true;
	recursion(idx + 1, cnt + 1);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		recursion(0,0);

		cout << '#' << tc << ' ' << ans << "\n";

	}


}
