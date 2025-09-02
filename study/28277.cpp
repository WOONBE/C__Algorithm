#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0);

set<int> v[500001];

int main() {
    First;

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int n, num;
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> num;
            v[i].insert(num);
        }
    }

    while (Q--) {
        int op, a, b;
        cin >> op;
        if (op == 1) {
            cin >> a >> b;

            if (v[a].size() < v[b].size()) {
                v[a].swap(v[b]);
            }

            v[a].insert(v[b].begin(), v[b].end());
            v[b].clear();

        } else {
            cin >> a;
            cout << v[a].size() << "\n";
        }
    }

    return 0;
}