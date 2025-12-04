#include <bits/stdc++.h>
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N,M,X,srt,ed;
vector<int> v[100001];
vector<int> rev_v[100001];
int visited[100001];

int bfs(int srt_node,vector<int> node[]){
    int cnt = 0;
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(srt_node);
    visited[srt_node] = 1;

    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(auto nxt : node[cur]){
            if(visited[nxt]) continue;
            visited[nxt] = 1;
            q.push(nxt);
            cnt++;
        }

    }
    return cnt;
}

int main(){
    First
    cin >> N >> M >> X;

    for(int i=0; i<M; i++){
        cin >> srt >> ed;
        v[srt].push_back(ed);
        rev_v[ed].push_back(srt);
    }

    //나보다 잘한 사람수는 역방향 간선을, 못한 사람수는 정방향 간선으로 go
    int high_rank = bfs(X,rev_v);

    int low_rank = bfs(X,v);

    cout << high_rank + 1 << ' ' << N - low_rank << "\n";
}