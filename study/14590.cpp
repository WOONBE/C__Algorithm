#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2001], ans;
bool visited[2001];

void dfs(int u) {
    visited[u] = 1;
    for (auto &v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
    ans.push_back(u);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x) adj[i].push_back(j);
        }
    }

    dfs(1);
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    for (auto &i : ans) cout << i << ' ';
}