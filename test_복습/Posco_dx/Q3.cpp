#include <iostream>
#include <string>
#include <map>
using namespace std;

string missingLowercaseLetters(string& sentence) {
    // 알파벳 개수를 저장할 map 생성 (알파벳: 카운트)
    map<char, int> letterCount;

    // 모든 알파벳을 0으로 초기화
    for (char c = 'a'; c <= 'z'; ++c) {
        letterCount[c] = 0;
    }

    // 입력받은 sentence에서 알파벳 카운트
    for (char c : sentence) {
        if (isalpha(c)) {
            letterCount[tolower(c)]++;  // 대소문자 구분 없이 소문자로 변환하여 카운트
        }
    }

    // 결과를 저장할 string
    string result;

    // 등장하지 않은 알파벳들을 결과에 추가
    for (char c = 'a'; c <= 'z'; ++c) {
        if (letterCount[c] == 0) {
            result += c;
        }
    }

    // 만약 모든 알파벳이 등장했다면 "perfect" 반환
    if (result.empty()) {
        return "perfect";
    }

    return result;
}

int main() {
    string sentence;
    cout << "Enter a sentence: ";
    getline(cin, sentence);

    string result = missingLowercaseLetters(sentence);
    cout << result << "\n";

    return 0;
}
