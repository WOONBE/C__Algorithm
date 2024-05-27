
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define RED 2
#define BLUE 3

using namespace std;

int visited[20001];
vector<int> adj[20001];
int node, edge;
int T,st,ed;
void init(){
    memset(visited,0, sizeof(visited));
    memset(adj, 0, sizeof(adj));
}

void dfs(int start){
    //방문안한 점이면 RED
    if (visited[start] == 0)
        visited[start] = RED;

    //연결된 점들 방문
    for (int i = 0; i < adj[start].size(); i++)
    {
        int idx = adj[start][i];
        if (visited[idx] == 0) //방문 안한 점이면
        {
            //현재 정점과 반대되는 색깔로 칠한다
            if (visited[start] == RED)
                visited[idx] = BLUE;
            else if (visited[start] == BLUE)
                visited[idx] = RED;

            //dfs 재귀
            dfs(idx);
        }
    }
}
/* 이분그래프 검사 */
int check()
{
    //인접한 노드와 색이 같으면 이분그래프 X
    for (int i = 1; i <= node; i++)
    {
        //연결된게 자기자신 뿐일 경우엔 size가 0이라서 돌아가지 않는다.
        for (int j = 0; j < adj[i].size(); j++)
        {
            int idx = adj[i][j];
            if (visited[i] == visited[idx])
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for(int t=0; t<T; t++){

        init();
        cin >> node >> edge;
        for(int i=0; i<edge; i++){
            cin >> st >> ed;
            adj[st].push_back(ed);
            adj[ed].push_back(st);
        }
        for(int i=1; i<=node; i++){
            if(visited[i] == 0){
                dfs(i);
            }
        }

        if (check() == 0)
            cout << "NO\n";
        else
            cout << "YES\n";


    }
}