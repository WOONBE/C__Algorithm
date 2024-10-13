#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string str1, str2;

// 주어진 시각을 1초 증가시키는 함수
string increaseTime(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));

    s++; // 1초 증가
    if (s == 60) {
        s = 0;
        m++;
        if (m == 60) {
            m = 0;
            h++;
            if (h == 24) {
                h = 0; // 24시간 넘어가면 0으로 초기화
            }
        }
    }

    // 다시 문자열 형태로 반환
    string newTime = (h < 10 ? "0" : "") + to_string(h) + ":" +
                     (m < 10 ? "0" : "") + to_string(m) + ":" +
                     (s < 10 ? "0" : "") + to_string(s);
    return newTime;
}

// 숫자의 종류를 계산하는 함수
bool hasTwoUniqueDigits(const string& time) {
    unordered_map<char, int> digitCount;

    // 시간 문자열에서 각 숫자를 카운트
    for (char c : time) {
        if (isdigit(c)) {  // 숫자만 고려
            digitCount[c]++;
        }
    }

    // 숫자의 종류가 정확히 2개일 경우 true 반환
    return digitCount.size() == 2;
}

void solve(string s1, string s2) {
    int count = 0;

    while (s1 <= s2) {
        if (hasTwoUniqueDigits(s1)) {
            count++; // 숫자 종류가 2개일 경우 카운트 증가
        }
        s1 = increaseTime(s1); // 시간을 1초 증가
    }

//    // 마지막 s2도 체크
//    if (hasTwoUniqueDigits(s2)) {
//        count++;
//    }

    cout << count << "\n"; // 결과 출력
}

int main() {
    First

    // 두 개의 시간 입력
    cin >> str1 >> str2;

    // 주어진 시간 사이의 자연수가 2종류인 경우 계산
    solve(str1, str2);

    return 0;
}
