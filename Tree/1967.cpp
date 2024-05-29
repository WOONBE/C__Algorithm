#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<pair<int,int>> edges[10001];

int node,mx_cost = 0;
int deep_node = 1;

void dfs(int cur, int prev, int cost){
    if(cost > mx_cost){
        mx_cost = cost;
        deep_node = cur;
    }
    for(int i=0; i<edges[cur].size(); i++){ //이부분 범위 수정
        if(edges[cur][i].first != prev){ //방문 x 노드면
            dfs(edges[cur][i].first, cur, cost + edges[cur][i].second);
        }
    }

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> node;
    for(int i=1; i<=node-1; i++){ //입력부분 노드 수가 아니라 간선수임
        int start, end, weigh;
        cin >> start >> end >> weigh;
        edges[start].push_back({end,weigh});
        edges[end].push_back({start,weigh});
    }

    dfs(1,0,0); //dfs 돌려서 가장 먼 거리의 노드 find(deep_node)
    mx_cost = 0;
    dfs(deep_node,0,0); //1번 노드에서 가장 먼 노드에서부터 가장 먼 노드까지의 거리를 dfs를 이용하여 구한다

    cout << mx_cost;
}
