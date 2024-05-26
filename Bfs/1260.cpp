#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <utility>


using namespace std;
vector<int> adj[10001];
bool visited[10001];
int node, edge, start;
int st, ed;
queue<int> q;

void dfs(int start){
    if(visited[start]) return;
    visited[start] = true;
    cout << start << ' ';
    for(auto u : adj[start]){
        dfs(u);
    }
}

void bfs(int x){
    visited[x] = true;
    q.push(x);
    while(!q.empty()){
        int s = q.front(); q.pop();
        cout << s << ' ';
         for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            q.push(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> node >> edge >> start;

    for(int i=0; i<edge; i++){
        cin >> st >> ed;
        adj[st].push_back(ed);
        adj[ed].push_back(st);
    }
    for (int i = 1; i <= edge;i++){
        sort(adj[i].begin(), adj[i].end()); // 낮은 숫자부터 탐색
    }

    dfs(start);

    memset(visited, 0, sizeof(visited));
    cout << "\n";

    bfs(start);
}
