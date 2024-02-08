#include <iostream>
#include <string>



using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	

	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		int cnt = 0;
		string str;
		cin >> str;
		if (str[0] == '1') {
			cnt++;
		}
		for (int i = 0; i < str.size() -1; i++) {
			if (str[i] != str[i + 1]) {
				cnt++;
			}
				
		}

		cout << "#" << tc << " " << cnt << '\n';
	}
}
	
	


