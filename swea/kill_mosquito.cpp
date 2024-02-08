#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	int arr[20][20];
	
	cin >> t;
	for (int tc = 0; tc < t; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		int max = 0;
		for (int i = 0; i < n - m+1; i++) {
			for (int j = 0; j < n - m+1; j++) {
				int sum = 0;
				for (int k = i; k < i + m; k++) {
					for (int h = j; h < j + m; h++) {
						sum += arr[k][h];

					}
					if (sum > max) {
						max = sum;

					}
				}
			}

		}cout << "#" << tc+1 <<" "<< max << '\n';
	}
	return 0;
}

