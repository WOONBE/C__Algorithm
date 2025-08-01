#include <bits/stdc++.h>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
const int INF = 1e8;
int T,n,m,t,s,g,h,a,b,d,x;
vector<pair<int,int>> v[2001]; //d,b(비용, 노드)
vector<int> dest;
int dist[2001][2001];

//시작점, 중간점 2개에서 각각 다익스트라
//이후에 최단거리랑 거쳐가는 거리랑 같을때 해당 경로 목적지를 답에 추가

void dijkstra(int srt_node){

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    dist[srt_node][srt_node] = 0;
    pq.push({0,srt_node});

    while(!pq.empty()){
        auto cur_node = pq.top().second;
        auto cur_dist = pq.top().first;
        pq.pop();

        if(dist[srt_node][cur_node] < cur_dist) continue;

        for(auto nxt : v[cur_node]){
            auto nxt_dist = nxt.first;
            auto nxt_node = nxt.second;

            if(dist[srt_node][nxt_node] > cur_dist + nxt_dist){
                dist[srt_node][nxt_node] = cur_dist + nxt_dist;
                pq.push({dist[srt_node][nxt_node],nxt_node});
            }
        }
    }

}

int main(){
    First

    cin >> T;

    while(T--){
        cin >> n >> m >> t;

        for(int i=1; i<=n; i++){
            v[i].clear();
        }
        dest.clear();

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dist[i][j] = INF;
            }
        }
        cin >> s >> g >> h;

        for(int i=0; i<m; i++){
            cin >> a >> b >> d;
            v[a].push_back({d,b});
            v[b].push_back({d,a});
        }
        for(int i=0; i<t; i++){
            cin >> x;
            dest.push_back(x);
        }
        dijkstra(s);
        dijkstra(g);
        dijkstra(h);

        vector<int> ans;
        for(int i=0; i<dest.size(); i++){
            int path = dist[s][dest[i]];
            int path1 = dist[s][g] + dist[g][h] + dist[h][dest[i]];
            int path2 = dist[s][h] + dist[h][g] + dist[g][dest[i]];
            if(path == INF || path1 == INF || path2 == INF) continue;
            if(path == min(path1,path2)) ans.push_back(dest[i]);
        }
        sort(ans.begin(),ans.end());

        for(int i=0; i<ans.size(); i++){
            cout << ans[i];
            if(i != ans.size() -1){
                cout << ' ';
            }
        }cout << "\n";
    }
    return 0;

}