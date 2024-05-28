#include <iostream>
#include <vector>

int adj[1001];


//트리 순회 by dfs
void dfs(int s,int e ){ //현재노드 s, 이전노드 e
    for(auto u: adj[s]){
        if(u != e) //방문한 적이 없으면
            dfs(u,s);
    }
}
dfs(x,0); // 노드 x에서 탐색 시작

void dfs1(int s, int e){
    count[s] = 1;
    for(auto u: adj[s]){
        if(u==e) continue;
        dfs(u,s);
        count[s] += count[u];
    }
}


int main(){


}