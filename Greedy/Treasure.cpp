#include <iostream>
#include <algorithm>

using namespace std;
int n;
int arr1[100];
int arr2[100];

bool compare(int a, int b) {
	return a > b; // a가 b보다 크면 true를 반환하여 내림차순으로 정렬
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n, compare);
	

	int result = 0;
	

	for (int i = 0; i <= n; i++) {
		result += arr1[i] * arr2[i];
	}
	cout << result << "\n";


}
