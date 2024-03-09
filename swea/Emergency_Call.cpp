#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int ans, n,start,from,to;
vector<int> adj[101];
int dist[101];

int init(){
    ans = 0;
    memset(adj,0,sizeof(adj));
    memset(dist,0,sizeof(dist));
}


int input(){
    cin >> n >> start;
    for(int i=0; i<n/2; i++){
        cin >> from >> to;
        adj[from].push_back(to);
    }
}
int bfs(int st){
    queue<int> q;
    q.push(st);
    dist[st] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for(int i=0; i<adj[cur].size(); i++){
            auto nxt = adj[cur][i];
            if(dist[nxt] == 0){
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int tc=1; tc<=10; tc++){
        init();
        input();
        bfs(start);
        int ans = start;
        for(int i = 1; i< 101; i++){
            if(dist[i] >= dist[ans]){
                ans = i;
            }
        }
        cout << '#' << tc << ' ' << ans << "\n";
    }
}
