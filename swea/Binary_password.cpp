#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, M, odd_num, even_num,sum_value, last_i, last_j,tc;
vector<string> v;
string arr[56]; 
string scan[] = { "0001101", "0011001", "0010011", "0111101", "0100011", "0110001",
					"0101111", "0111011", "0110111", "0001011" }; //풀이는 맞는데 scan 입력부가 이상해서 오류
string password, realcode;


void input() { //입력
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

}

void find_last_code() { //어차피 끝은 1이라 끝이 1인부분위치  find
	last_i = 0;
	last_j = 0;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = M - 1; j >= 0; j--) {
			if ( arr[i][j] == '1') {
				last_i = i;
				last_j = j;

			}
			if (last_i != 0) {
				break;
			}
				
		}
	}
}
void findPassword() { //한줄 위치 구해서 나중에 reverse시킬거임
	password = ' ';
		for (int i = last_i; i >= last_i; i--) {
			for (int j = last_j; j > last_j - 56; j--) {
				password += arr[i][j];
			}
	}

}

void splitCode() { //7줄씩 끊어서 저장
	string temp_code = "";

	for (int i = 0; i < password.size(); i++) {
		if (temp_code.size() == 7) {
			v.push_back(temp_code);
			temp_code = "";
			
		}
		temp_code += password[i];

	}
	v.push_back(temp_code);
}

void toRealCode() { //끊어서 저장한 코드를 실수로 변경
	realcode = "";
	for (auto code : v) {
		for (int i =0 ; i < 10; i++) {
			if (code == scan[i]) {
				realcode += to_string(i);
			}
		}
	}
}

void checkRealCode() { //홀수자리랑 짝수자리 합 및 총합 계산
	odd_num = 0;
	even_num = 0;
	sum_value = 0;
	for (int i = 0; i < realcode.size(); i++) {
		if (i % 2 == 0) {
			odd_num += realcode[i] - '0';
		}
		else {
			even_num += realcode[i] - '0';
		}
		sum_value += realcode[i] - '0';
	}
}
void print() { //특정 케이스에서 총합 리턴
	cout << '#' << tc+1 << " ";
	if ((3 * odd_num + even_num) % 10 == 0) {
		cout << sum_value << "\n";
	}
	else {
		cout << 0 << "\n";
	}

}


int main() {
	ios::sync_with_stdio(0); //여기로 위치 안잡으면 반복하면서 오류뜸
	cin.tie(0);
	cin >> T;

	for (tc = 0; tc < T; tc++) {


		input();
		find_last_code();
		findPassword();
		reverse(password.begin(), password.end());
		splitCode();
		toRealCode();
		checkRealCode();
		print();

		v.clear();
	}
	return 0;
		

}
