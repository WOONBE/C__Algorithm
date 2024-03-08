#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;

using namespace std;

int n,m,a,b,c;
int parent[1000001];
vector<int> ans;




int find(int tar) {
	if (tar == parent[tar]) //여기 오타나서 통과 못했음
		return tar;
	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;

}
void union_find(int x, int y) {
	int t1 = find(x);
	int t2 = find(y);

	if (t1 == t2) {
		return;

	}
	parent[t2] = t1;

}
int isSameParent(int x, int y) {
	int t1 = find(x);
	int t2 = find(y);
	if (t1 == t2) {
		return 1;
	}
	else {
		return 0;
	}
}

void init() {
	ans.clear();

	for (int i = 0; i < 1000001; i++) {
		parent[i] = i;

	}
}




void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		//union_find로 묶음
		if (a == 0) {
			union_find(b, c);
		}
		else {
			ll num = isSameParent(b, c);
			ans.push_back(num);

		}

	}
}



int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		init();
		input();
		cout << '#' << tc << ' ';
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i];
			}
			cout << "\n";

	}

}
