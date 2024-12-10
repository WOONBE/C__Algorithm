#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;
vector<string> v;
int countCompoundWords(const vector<string>& words) {
    unordered_set<string> wordSet(words.begin(), words.end()); // 단어를 빠르게 조회하기 위한 집합
    int count = 0;

    for (const string& word1 : words) {
        for (const string& word2 : words) {
            if (word1 == word2) continue; // 같은 단어끼리는 스킵

            // 첫 번째 단어의 마지막 글자와 두 번째 단어의 첫 글자가 겹칠 때 겹침 제거
            if (word1.back() == word2.front()) {
                string combined = word1 + word2.substr(1); // 겹침 제거 후 합성어 생성
                if (wordSet.count(combined)) { // 합성어가 wordSet에 있으면 카운트
                    count++;
                    v.push_back(combined);
                }
            }
                string combined = word1 + word2;
                if (wordSet.count(combined)) { // 합성어가 wordSet에 있으면 카운트
                    count++;
                    v.push_back(combined);
                }
            }

    }

    return count;
}

int main() {
    vector<string> words = {"sun", "ear", "ring", "travel", "sunearr", "earring", "earing", "travelear"};

    int result = countCompoundWords(words);
    cout << "Number of compound words: " << result << endl;

    for(auto i : v){
        cout << i << ' ';
    }

    return 0;
}
