#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MX 9987654321

vector<int> v;
vector<pair<int, int>> d;

int N, M, cmd, fst, scd;

typedef long long ll;

pair<int, int> init(int node, int st, int ed) {
    if (st == ed) {
        return d[node] = {v[st], st};
    }
    int mid = (st + ed) / 2;

    pair<int, int> left = init(node * 2, st, mid);
    pair<int, int> right = init(node * 2 + 1, mid + 1, ed);
    d[node] = (left.first <= right.first) ? left : right;
    return d[node];
}

pair<int, int> query(int node, int st, int ed, int left, int right) {
    if (ed < left || right < st) {
        return {MX, -1};
    }
    if (left <= st && ed <= right) {
        return d[node];
    }
    int mid = (st + ed) / 2;
    pair<int, int> l_idx = query(node * 2, st, mid, left, right);
    pair<int, int> r_idx = query(node * 2 + 1, mid + 1, ed, left, right);

    return (l_idx.first <= r_idx.first) ? l_idx : r_idx;
}

void change_val(int node, int st, int ed, int idx, int val) {
    if (st == ed) {
        v[idx] = val;
        d[node] = {val, idx};
        return;
    }
    int mid = (st + ed) / 2;
    if (idx <= mid) {
        change_val(node * 2, st, mid, idx, val);
    } else {
        change_val(node * 2 + 1, mid + 1, ed, idx, val);
    }
    d[node] = (d[node * 2].first <= d[node * 2 + 1].first) ? d[node * 2] : d[node * 2 + 1];
}

int main() {
    First;

    cin >> N;
    v.assign(N, 0);
    d.assign(4 * N, {MX, -1});

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    init(1, 0, N - 1);

    cin >> M;

    for (int i = 0; i < M; i++) {
        cin >> cmd >> fst >> scd;
        if (cmd == 1) {
            change_val(1, 0, N - 1, fst - 1, scd);
        }
        if (cmd == 2) {
            pair<int, int> result = query(1, 0, N - 1, fst - 1, scd - 1);
            cout << result.second + 1 << "\n";
        }
    }

    return 0;
}
