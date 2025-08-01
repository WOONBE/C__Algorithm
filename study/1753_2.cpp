#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int V,E,srt,a,b,c;
const int INF = 1e9;
vector<pair<int,int>> v[20001];
int dist[20001];

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};


void dijkstra(int cur){
    priority_queue<pair<int,int>, vector<pair<int,int>>,cmp> pq;
    dist[cur] = 0;
    pq.push({cur,0});

    while(!pq.empty()){
        int cur_node = pq.top().first;
        int cur_dist = pq.top().second;
        pq.pop();

        if(dist[cur_node] < cur_dist) continue;

        for(auto nxt : v[cur_node]){
            int nxt_node = nxt.first;
            int nxt_dist = nxt.second;

            if(dist[nxt_node] > dist[cur_node] + nxt_dist){
                dist[nxt_node] = dist[cur_node] + nxt_dist;
                pq.push({nxt_node,dist[nxt_node]});
            }
        }

    }
}

int main(){
    First

    cin >> V >> E;
    cin >> srt;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    fill(dist, dist + V + 1, INF);

    dijkstra(srt);

    for(int i=1; i<=V; i++){
        if(dist[i] == INF){
            cout << "INF" << "\n";
        }else{
            cout << dist[i] << "\n";
        }
    }
    return 0;
}