#include <iostream>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int tc, T; cin >> T;
	int arr[49][49];
	for (tc = 1; tc <= T; tc++) {
		int N, W, sum; cin >> N;
		string n;
		for (int i = 0; i < N; i++) {
			cin >> n;
			for (int j = 0; j < N; j++) {
				arr[i][j] = n[j] - '0';
			}
		}

		sum = 0;
		for (int i = 0; i < N; i++) {
			if (i <= (N / 2)) {
				for (int j = (N / 2) - i; j <= (N / 2) + i; j++) {
					sum += arr[i][j];
				}
			}
			else {
				for (int j = i - (N / 2); j <= (N / 2) + (N - i) - 1; j++) {
					sum += arr[i][j];
				}
			}
		}

		cout << "#" << tc << " " << sum << "\n";;
	}

}

	
	


