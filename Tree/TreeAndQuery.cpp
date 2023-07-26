//
// Created by 김헌우 on 2023/07/26.
//못풀었음 + 코드 참조

#include <bits/stdc++.h>
using namespace std;

const int MXN = 10e5 + 10;
int N, R, Q, U, V, q, subTreeSize[MXN];
vector<int> adj[MXN];
vector<bool> vis(MXN);

int countSubtreeNode(int cur) {
    vis[cur] = true;
    for (auto nxt : adj[cur]) {
        if (vis[nxt]) continue;
        subTreeSize[cur] += countSubtreeNode(nxt); //자기값 + 밑의 노드값
    }
    subTreeSize[cur]++; //루트 포함시킴
    return subTreeSize[cur];
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N - 1; i++) {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    countSubtreeNode(R);
    while (Q--) {
        cin >> q;
        cout << subTreeSize[q] << '\n';
    }
}
