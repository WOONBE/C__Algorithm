#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N,M;
int srt,ed,cost;
int visited[50001];
vector<pair<int,int>> adj[50001];
int dist[50001];


struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.first > b.first;
    }
};

void dijkstra(int x){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    dist[x] = 0;
//    visited[x] = 1;
    pq.push({0,x}); //거리, 이전에 방문한 노드

    while(!pq.empty()){
        auto cur = pq.top();pq.pop();
        auto cur_dist = cur.first;
        auto cur_node = cur.second;
        if(visited[cur_node]) continue;
        visited[cur_node] = 1;

        for(auto i : adj[cur_node]){
            int nxt_node = i.first;
            int nxt_dist = i.second;

            if(cur_dist + nxt_dist < dist[nxt_node]){
                dist[nxt_node] = cur_dist + nxt_dist;
//                visited[nxt_node]= 1;
                pq.push({dist[nxt_node],nxt_node});
            }
        }
    }
}


int main(){
    First

    cin >> N >> M;
    for(int i=1; i<=N; i++){
        dist[i] = 2e9 +1;
    }

    for(int i=1; i<=M; i++){
        cin >> srt >> ed >> cost;
        adj[srt].push_back({ed,cost});
        adj[ed].push_back({srt,cost});

    }

    dijkstra(1);

    cout << dist[N] << "\n";


}