#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> adj[100005];
int visited[100005]; // 0: not visited, 1: visiting, 2: visited
int T, node, cnt, team_members;

void dfs(int start){
    visited[start] = 1; // 현재 노드 방문 중
    int next = adj[start][0]; // 다음 노드
    if (visited[next] == 0) { // 아직 방문하지 않은 노드
        dfs(next);
    } else if (visited[next] == 1) { // 사이클 발견
        for (int u = next; u != start; u = adj[u][0]) {
            team_members++;
        }
        team_members++; // 사이클 시작 노드도 포함
    }
    visited[start] = 2; // 현재 노드 방문 완료
}

void init(int n){
    cnt = 0;
    team_members = 0;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        visited[i] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> node;
        init(node);
        for(int i = 1; i <= node; i++){
            int ed;
            cin >> ed;
            adj[i].push_back(ed);
        }

        for(int i = 1; i <= node; i++) {
            if (visited[i] == 0) {
                dfs(i);
            }
        }
        cout << node - team_members << "\n";
    }
    return 0;
}
