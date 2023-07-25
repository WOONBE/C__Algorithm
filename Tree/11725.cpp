//
// Created by 김헌우 on 2023/07/25.
//
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100001];
int p[100001]; //부모 여부

void dfs(int cur) {
    for (int nxt : adj[cur]) {
        if (p[cur] == nxt) continue; //부모는 넣을 필요가 없다(이미 방문했가 때문에)
        p[nxt] = cur;
        dfs(nxt);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 2; i <= n; i++) cout << p[i] << '\n';
}