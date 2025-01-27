#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, num;
vector<pair<int, int>> v;
int tree[500005];

int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int idx, int val) {
    while (idx <= N) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main() {
    First

    cin >> N;
    v.resize(N); // 벡터 크기 초기화

    // 입력 처리
    for (int i = 0; i < N; i++) {
        cin >> num;
        v[i] = {num, i + 1}; // 값과 원래 인덱스를 저장
    }

    // 값 기준으로 정렬
    sort(v.begin(), v.end());

    // 정렬된 순서대로 인덱스 매핑
    vector<int> indexed(N + 1);
    for (int i = 0; i < N; i++) {
        indexed[v[i].second] = i + 1; // 원래 인덱스에 정렬된 순서 부여
    }

    // 펜윅 트리를 활용해 결과 계산
    for (int i = 1; i <= N; i++) {
        int idx = indexed[i];
        cout << i - sum(idx - 1) << "\n"; // 현재까지의 결과 계산
        update(idx, 1); // 현재 위치를 트리에 추가
    }

    return 0;
}
