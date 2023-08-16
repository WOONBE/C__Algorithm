//
// Created by 김헌우 on 2023/08/16.
//

#include <bits/stdc++.h>
using namespace std;

int v, e, a, b;
vector <int> adj[105];
bool vis[105];
int ans = 0;

void dfs(int cur){
    vis[cur] = true;
    for(auto nxt: adj[cur]){
        if(vis[nxt]) continue;
        ans++;
        dfs(nxt);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    while(e--){
        cin >> a >> b;
        adj[a].push_back(b); //양방향이라서 이렇게 두번 넣는다
        adj[b].push_back(a);
    }

    dfs(1);
    cout << ans;
}