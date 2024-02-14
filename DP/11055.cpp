#include <iostream>
#include <algorithm>
// 99%에서 계속 멈췄었음, 마지막 cout 할때 max_element 범위 재조정하니 통과
using namespace std;
int n;
int arr[1010];
int d[1010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		d[i] = arr[i];
		
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				d[i] = max(d[i], d[j] + arr[i]); //아이디어는 맞았는데 출력할때 문제
			}
		}
	}
	cout << *max_element(d + 1, d+ n+ 1);
	

}
