#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int t;
		t = i;

		bool check = true;

		while (t) {
			if (t % 10 && (t % 10) % 3 == 0) { //36같은 경우는 while문을 한번 더 돌면서 자동으로 --으로 출력되게 한다
				cout << "-";
				check = false;
			}
			t /= 10;
		}
		if (check) 
			cout << i;
		cout << " ";
	}return 0;

}
