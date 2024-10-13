#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, K;
vector<int> words;
const int ALPHABET = 26;

int learned = 0;
int maxWords = 0;

//읽을 수 있는 단어들 cnt
int countReadableWords() {
    int count = 0;
    for (int word : words) {
        if ((word & learned) == word) {
            count++;
        }
    }
    return count;
}

//dfs 돌면서
void dfs(int idx, int toLearn) {
    if (toLearn == 0) {
        maxWords = max(maxWords, countReadableWords());
        return;
    }

    for (int i = idx; i < ALPHABET; i++) {
        if ((learned & (1 << i)) == 0) {
            learned |= (1 << i);  // 현재 알파벳 추가
            dfs(i + 1, toLearn - 1);  // 재귀 호출
            learned &= ~(1 << i);  // 알파벳 제거 (백트래킹)
        }
    }
}

int main() {
    cin >> N >> K;

    if (K < 5) {
        cout << 0 << "\n";
        return 0;
    }

    // 필수로 배워야 하는 글자들 'a', 'n', 't', 'i', 'c'
    learned |= (1 << ('a' - 'a'));
    learned |= (1 << ('n' - 'a'));
    learned |= (1 << ('t' - 'a'));
    learned |= (1 << ('i' - 'a'));
    learned |= (1 << ('c' - 'a'));

    // 단어를 비트마스크로 변환
    words.resize(N);
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        int mask = 0;
        for (char c : word) {
            mask |= (1 << (c - 'a'));
        }
        words[i] = mask;
    }

    // dfs로 배울 글자를 선택
    dfs(0, K - 5);

    cout << maxWords << "\n";
}
