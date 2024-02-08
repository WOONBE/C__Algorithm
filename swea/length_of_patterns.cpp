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
		string str, temp;
		cin >> str;
		temp.push_back(str[0]);
		for (int i = 1; i < str.size(); i++) {
			if (temp != str.substr(temp.size(), i))
				temp.push_back(str[i]);
			else
				break;
		}
		cout << "#" << tc << " " << temp.size() << '\n';
	}
    return 0;
}
	
	


