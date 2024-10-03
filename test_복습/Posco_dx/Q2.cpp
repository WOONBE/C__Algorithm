#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    // 알파벳의 빈도를 저장할 배열 (소문자만 고려하여 26칸짜리 배열 사용)
    int arr[26] = {0};

    // 알파벳의 빈도를 카운트
    for (int i = 0; i < s.length(); i++) {
        arr[s[i] - 'a']++;  // 'a'를 빼서 알파벳에 대응하는 인덱스에 접근
    }
    int odd_count = 0;
    // 빈도가 홀수인 알파벳을 찾기
    for (int i = 0; i < 26; i++) {
        if (arr[i] % 2 != 0) {
            odd_count++;
        }
    }

    cout << "Number of characters with odd frequency: " << odd_count << endl;
    return 0;
}


