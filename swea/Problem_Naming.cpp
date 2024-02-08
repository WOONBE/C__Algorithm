#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int n;
		int mx = 0;
		cin >> n;
		vector<bool> v(26, false);
		for (int i = 0; i < n; i++) {
			string str;

			cin >> str;
			v[str[0] - 'A'] = true;

		}
		if (v[0]) {
			mx++;
		}
		for (int i = 1; i < 26; i++) {
			if (v[i] && v[i - 1]) {
				mx++;
			}
			else
				v[i] = false;
		}

		cout << "#" << tc << " " << mx << '\n';
	}
}
	
	


