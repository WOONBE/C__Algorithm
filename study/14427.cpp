#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<int, int> pii;

int N, M, num, a, b;
vector<int> v;
vector<pii> d;  // 세그먼트 트리: (값, 인덱스)

// 세그먼트 트리 초기화
pii init(int node, int srt, int ed) {
    if (srt == ed) {
        return d[node] = {v[srt], srt};  // (값, 인덱스)
    }
    int mid = (srt + ed) / 2;
    pii l = init(node * 2, srt, mid);
    pii r = init(node * 2 + 1, mid + 1, ed);
    return d[node] = min(l, r);  // 값이 같으면 인덱스가 작은 쪽
}

// 쿼리: 최소값 위치 찾기
pii query(int node, int srt, int ed, int left, int right) {
    if (right < srt || ed < left) return {1e9 + 1, 1e9};  // 무시할 큰 값
    if (left <= srt && ed <= right) return d[node];
    int mid = (srt + ed) / 2;
    pii l = query(node * 2, srt, mid, left, right);
    pii r = query(node * 2 + 1, mid + 1, ed, left, right);
    return min(l, r);
}

// 값 변경
pii change(int node, int srt, int ed, int idx, int val) {
    if (idx < srt || ed < idx) return d[node];
    if (srt == ed) return d[node] = {val, idx};
    int mid = (srt + ed) / 2;
    pii l = change(node * 2, srt, mid, idx, val);
    pii r = change(node * 2 + 1, mid + 1, ed, idx, val);
    return d[node] = min(l, r);
}

int main() {
    First
    cin >> N;
    v.assign(N, 0);
    d.assign(N * 4, {0, 0});

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    cin >> M;
    init(1, 0, N - 1);

    while (M--) {
        cin >> num;
        if (num == 1) {
            cin >> a >> b;
            change(1, 0, N - 1, a - 1, b);  // 1-based -> 0-based
        } else if (num == 2) {
            cout << query(1, 0, N - 1, 0, N - 1).second + 1 << '\n';
        }
    }

    return 0;
}
