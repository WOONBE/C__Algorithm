#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[1001];
bool visited[1001];
int T,st,ed,node,cnt;

void dfs(int start){
    if(visited[start]) return;
    visited[start] = true;
    for(auto u : adj[start]){
        dfs(u);
    }
}
void init(){
    cnt = 0;
    memset(adj, 0, sizeof(adj));
    memset(visited,0, sizeof(visited));

}

int main(){
    cin >> T;
    for(int t=0; t<T; t++){
        init();
        cin >> node;
        for(int i=1; i<=node; i++){
            st = i;
            cin >> ed;
            adj[st].push_back(ed);
        }

        for(int i=1; i<=node; i++) {
            if (visited[i]) continue;
            dfs(i);
            cnt++;
        }
        cout << cnt << "\n";
    }
}
