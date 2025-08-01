#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N,E,a,b,c,x1,x2,dist[801][801];

vector<pair<int,int>> v[801];
const int INF = 1e8;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return a.second > b.second;
    }
};


void dijkstra(int srt_node){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    dist[srt_node][srt_node] = 0;
    pq.push({srt_node,0});

    while(!pq.empty()){
        auto cur_node = pq.top().first;
        auto cur_dist = pq.top().second;
        pq.pop();

        if(dist[srt_node][cur_node] < cur_dist) continue;

        for(auto nxt : v[cur_node]){
            auto nxt_node = nxt.first;
            auto nxt_dist = nxt.second;

            if(dist[srt_node][nxt_node] > cur_dist + nxt_dist){
                dist[srt_node][nxt_node] = cur_dist + nxt_dist;
                pq.push({nxt_node,dist[srt_node][nxt_node]});
            }
        }
    }
}


int main(){
    First

    cin >> N >> E;
    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    cin >> x1 >> x2;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            dist[i][j] = INF;
        }
    }
    dijkstra(1);
    dijkstra(x1);
    dijkstra(x2);

    int way1 = dist[1][x1] + dist[x1][x2] + dist[x2][N];
    int way2 = dist[1][x2] + dist[x2][x1] + dist[x1][N];

    int result = min(way1,way2);
    if(result >= INF){
        cout << -1 << "\n";
    }else{
        cout << result << "\n";
    }
    return 0;
}