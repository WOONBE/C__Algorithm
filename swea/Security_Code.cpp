#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int code[5][5][5];
int ans;
int T, N, M;
int arr[2005][2005];

int hexaToBinary[16][4] = {
	{0,0,0,0},
	{0,0,0,1},
	{0,0,1,0},
	{0,0,1,1},
	{0,1,0,0},
	{0,1,0,1},
	{0,1,1,0},
	{0,1,1,1},
	{1,0,0,0},
	{1,0,0,1},
	{1,0,1,0},
	{1,0,1,1},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,0},
	{1,1,1,1}
};


void setting() {
	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {

			for (int k = 0; k < 5; k++) {
				code[i][j][k] = -1;


			}
		}
	}
	code[2][1][1] = 0;
	code[2][2][1] = 1;
	code[1][2][2] = 2;
	code[4][1][1] = 3;
	code[1][3][2] = 4;
	code[2][3][1] = 5;
	code[1][1][4] = 6;
	code[3][1][2] = 7;
	code[2][1][3] = 8;
	code[1][1][2] = 9;

}

void init() {
	ans = 0;
	memset(arr, 0, sizeof(arr));
}

void Input()
{
	cin >> N >> M;
	char input;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> input;

			if (input <= '9')
			{
				input = input - '0';
			}
			else
			{
				input = input - 'A' + 10;
			}

			for (int k = 0; k < 4; k++)
			{
				arr[i][j * 4 + k] = hexaToBinary[input][k];
			}
		}
	}
}
	


void func() {
	int ans_idx = 7;
	int ans_arr[8] = { 0, };
	
	for (int i = 1; i < N; i++) {
		for (int j = (M * 4) - 1; j >= 0; j--) { //뒤에서 부터 탐색,  비율 find, M*4는 16진수가 2진수 되었기에 범위 up
			int check[3] = { 0,0,0 };

			if (arr[i][j] == 1 && arr[i - 1][j] == 0) {
				while (arr[i][j] == 1) {
					check[2]++;
					
					j--;
				}
				while (arr[i][j] == 0) {
					check[1]++; 
					j--;
				}
				while (arr[i][j] == 1) {
					check[0]++;
					j--;
				}
				j++;

				int Min = check[2];

				if (check[1] < Min) {
					Min = check[1];
				}
				if (check[0] < Min) {
					Min = check[0];
				}

				for (int i = 0; i < 3; i++) {
					check[i] = check[i] / Min;
				}
				ans_arr[ans_idx--] = code[check[0]][check[1]][check[2]];
				if (ans_arr[ans_idx + 1] == -1) {
					ans = 0;
					return;
				}
				if (ans_idx == -1)
				{
					int value = (ans_arr[0] + ans_arr[2] + ans_arr[4] + ans_arr[6]) * 3 + (ans_arr[1] + ans_arr[3] + ans_arr[5] + ans_arr[7]);

					if (value % 10 == 0) {
						for (int t = 0; t < 8; t++) {
							ans += ans_arr[t];
						}
						
						
					}ans_idx = 7; //이부분 조건문 안에 들어갔다가 오류
				}
			}

		}
	}

}

void Solve() {
	setting();
	int tc;
	cin >> tc;
	for (int T = 1; T <= tc; T++) {
		init();
		Input();
		func();
		cout << "#" << T << " " << ans << "\n";
	}
}
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Solve();
	return 0;
}
