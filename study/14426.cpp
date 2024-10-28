#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

string s[10001];  // 집합 S에 포함된 문자열
string s2[10001]; // 검사할 문자열
int N, M;

struct Node {
    bool valid; // 현재 노드가 끝나는 문자열 여부
    map<int, int> children; // 자식 노드들

    Node() {
        valid = false;
    }
};

vector<Node> trie;

// 노드 초기화 함수
int init() {
    Node x;
    trie.push_back(x);
    return trie.size() - 1; // 새 노드의 인덱스 반환
}

// 문자열을 트라이에 추가하는 함수
bool add(int node, string& s, int idx) {
    if (idx == s.size()) {
        trie[node].valid = true; // 문자열 끝을 마킹
        return true;
    }
    // 이미 유효한 문자열이 있으면 false
    if (trie[node].valid) {
        return false;
    }

    int c = s[idx]; // 현재 문자
    // 자식 노드가 없다면 새로운 노드 생성
    if (trie[node].children[c] == 0) {
        trie[node].children[c] = init(); // 새 노드 추가
    }

    // 다음 문자로 재귀 호출
    return add(trie[node].children[c], s, idx + 1);
}

// 접두사 여부를 확인하는 함수
bool search(int node, string& s, int idx) {
    if (idx == s.size()) {
        return true; // 문자열의 모든 문자가 포함된 경우
    }

    int c = s[idx]; // 현재 문자
    // 자식 노드가 없다면 false
    if (trie[node].children.count(c) == 0) {
        return false; // 해당 문자에 대한 자식 노드 없음
    }

    // 다음 문자로 재귀 호출
    return search(trie[node].children[c], s, idx + 1);
}

int main() {
    cin >> N >> M;
    int cnt = 0;

    // 집합 S에 포함된 문자열 입력
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    // 검사할 문자열 입력
    for (int i = 0; i < M; i++) {
        cin >> s2[i];
    }

    // 트라이 초기화
    trie.clear();
    init();

    // 문자열 집합 S의 모든 문자열을 트라이에 추가
    for (int i = 0; i < N; i++) {
        add(0, s[i], 0);
    }

    // 검사할 문자열 중 접두사인지 확인
    for (int i = 0; i < M; i++) {
        if (search(0, s2[i], 0)) { // 접두사인 경우
            cnt++;
        }
    }

    cout << cnt << "\n"; // 접두사인 문자열의 개수 출력
}
