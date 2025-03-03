#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define Fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, M;
vector<int> arr;
vector<int> segtree;

void build(int node, int start, int end) {
    if (start == end) {
        segtree[node] = arr[start];
    } else {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);
        segtree[node] = max(segtree[node * 2], segtree[node * 2 + 1]);
    }
}

int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return -1;
    if (l <= start && end <= r) return segtree[node];

    int mid = (start + end) / 2;
    return max(query(node * 2, start, mid, l, r), query(node * 2 + 1, mid + 1, end, l, r));
}

int main() {
    Fast
    cin >> N >> M;

    arr.resize(N + 1);
    segtree.resize(4 * (N + 1));

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    build(1, 1, N);

    for (int i = M; i <= N - M + 1; i++) {
        int left = max(1, i - M + 1);
        int right = min(N, i + M - 1);
        cout << query(1, 1, N, left, right) << ' ';
    }

    return 0;
}
