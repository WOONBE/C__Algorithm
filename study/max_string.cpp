#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 문자열 길이 제한을 위한 구조체
struct CharInfo {
    long long length; // 최종 길이 (10^15까지 가능하므로 long long)
    string str;       // 최종 문자열 (limit까지만 저장)
};

string solution(string s, vector<pair<char, string>> queries) {
    long long limit = s.length() * 2; // 제한 길이 (원본 길이 * 2)

    // 알파벳 A~Z에 대한 정보를 저장할 배열
    // 초기 상태: 길이는 1, 문자열은 자기 자신
    vector<CharInfo> info(26);
    for (int i = 0; i < 26; i++) {
        info[i].length = 1;
        info[i].str = string(1, 'A' + i);
    }

    // 쿼리를 역순으로 처리
    // 이유: 나중에 적용되는 변환 규칙을 먼저 확정지어야,
    // 그 이전 변환 규칙이 해당 결과를 참조할 수 있음
    for (int i = queries.size() - 1; i >= 0; i--) {
        char target = queries[i].first;     // 변경 대상 문자 (예: 'L')
        string word = queries[i].second;    // 변경될 단어 (예: "LL")

        int targetIdx = target - 'A';

        long long newLength = 0;
        string newStr = "";

        // word의 각 문자가 현재 시점에서 어떻게 변환되는지 합침
        for (char c : word) {
            int charIdx = c - 'A';

            // 길이 합산
            newLength += info[charIdx].length;

            // 문자열 합치기 (limit을 넘지 않도록 조절)
            if (newStr.length() < limit) {
                newStr += info[charIdx].str;
                // 합친 후 limit을 넘으면 자름
                if (newStr.length() > limit) {
                    newStr = newStr.substr(0, limit);
                }
            }
        }

        // 해당 알파벳의 정보 갱신
        info[targetIdx].length = newLength;
        info[targetIdx].str = newStr;
    }

    // 원본 문자열 S를 순회하며 최종 결과 생성
    long long totalLength = 0;
    string finalStr = "";

    for (char c : s) {
        int charIdx = c - 'A';

        // 전체 길이 계산
        totalLength += info[charIdx].length;

        // 문자열 생성 (limit까지만)
        if (finalStr.length() < limit) {
            finalStr += info[charIdx].str;
            if (finalStr.length() > limit) {
                finalStr = finalStr.substr(0, limit);
            }
        }
    }

    // 결과 반환 포맷팅
    if (totalLength > limit) {
        // 길이가 limit을 초과하면 "문자열 + 남은길이" 리턴
        return finalStr + " + " + to_string(totalLength - limit);
    } else {
        // 초과하지 않으면 문자열 그대로 리턴
        return finalStr;
    }
}

// 테스트를 위한 메인 함수
int main() {
    // Test Case 1
    string S1 = "HELLO";
    vector<pair<char, string>> queries1 = {
            {'L', "X"}, {'E', "WORLD"}, {'H', "HELLO"}, {'L', "LL"}
    };
    cout << "Test 1: " << solution(S1, queries1) << endl;
    // Expected: HELLLOWOR + 6

    // Test Case 2
    string S2 = "XYY";
    vector<pair<char, string>> queries2 = {
            {'Y', "R"}, {'X', "BA"}, {'R', "NA"}, {'A', "AA"}
    };
    cout << "Test 2: " << solution(S2, queries2) << endl;
    // Expected: BAANAA + 3

    return 0;
}