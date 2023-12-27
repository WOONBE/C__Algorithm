//
// Created by 김헌우 on 2023/08/17.
//
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[5001];
bool vis[5001];
int ans = 0;

void dfs() {
    stack<int> s;
    s.push(1);
    while (!s.empty()) {
        int cur = s.top();
        s.pop();
        vis[cur] = true;
        for (auto nxt: adj[cur]) {
            if (vis[nxt]) continue;
            vis[nxt] = true;
            ans++;
            if (cur == 1) s.push(nxt);
        }
    }
}

    int main() {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n, m;

        // 그래프 입력 처리
        cin >> n >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); //무방향이라 이렇게 처리 해줘야함(구현할때 이거 놓쳐서 런타임)
        }
        dfs();
        cout << ans;
    }

