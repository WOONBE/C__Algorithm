//2217

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr[100010];


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int result = 0;

	for (int i = 1; i <= n; i++) {
		result = max(result, arr[n - i] * i);
	}
	cout << result << "\n";


}
