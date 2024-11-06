#include <iostream>
#include <vector>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

long long a[1000001];
long long d[4000001]; // 세그먼트 트리 배열
long long lazy[4000001]; // lazy 배열
int N, M, K;

void init(int node, int start, int end) {
    if (start == end) {
        d[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    d[node] = d[node * 2] + d[node * 2 + 1];
}


void update_lazy(int node, int start, int end) {
    if (lazy[node] != 0) {
        d[node] += (end - start + 1) * lazy[node];
        if (start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}
long long query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);

    if (end < left || start > right) return 0;

    if (left <= start && end <= right) return d[node];

    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update_range(int node, int start, int end, int left, int right, long long val) {
    update_lazy(node, start, end);

    if (end < left || start > right) return;

    if (left <= start && end <= right) {
        d[node] += (end - start + 1) * val;
        if (start != end) {
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }

    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, left, right, val);
    update_range(node * 2 + 1, mid + 1, end, left, right, val);
    d[node] = d[node * 2] + d[node * 2 + 1];
}



int main() {
    First

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        int op;
        cin >> op;

        if (op == 1) { // 구간에 값 더하기
            int b, c;
            long long d;
            cin >> b >> c >> d;
            update_range(1, 1, N, b, c, d);
        } else if (op == 2) { // 구간 합 구하기
            int b, c;
            cin >> b >> c;
            cout << query(1, 1, N, b, c) << "\n";
        }
    }

    return 0;
}
