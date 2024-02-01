#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;



int n;
string str;
vector<string> v;


bool compare(string a, string b) {
	int length_A = a.size();
	int length_B = b.size();

	int sum_A = 0;
	int sum_B = 0;

	if (length_A != length_B) {
		return length_A < length_B;
	}
	for (int i = 0; i < length_A; i++) { // 숫자만 더한다. 
		if (isdigit(a[i])) sum_A += (a[i] - '0');
	}
	for (int i = 0; i < length_B; i++) {
		if (isdigit(b[i])) sum_B += (b[i] - '0');
	}
	if (sum_A != sum_B) return sum_A < sum_B;
	return a < b; // 사전순

}


int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(),compare);
	for (auto i :v) {
		cout << i << "\n";

	}


   
}

	
	


