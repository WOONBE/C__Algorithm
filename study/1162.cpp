#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 9223372036854775800
int N,M,K;

int srt,ed,num;
vector<pair<int,int>> v[50001]; //ed, 간선 비중
vector<vector<long long>> dist(10001, vector<long long >(21,INF)); //n번 노드까지 m번 포장했을때 최소 거리

void dijkstra(){

    priority_queue<pair<long long,pair<int,int>>> pq; //-비용, 노드번호, 포장 횟수

    pq.push({0,{1,0}});
    dist[1][0] = 0;



    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int cur_node = cur.second.first;
        int cur_pave = cur.second.second;
        int cur_dist = -cur.first; //-로 넣어줄거라 -붙여

        if(dist[cur_node][cur_pave] < cur_dist) continue;

        for(auto i : v[cur_node]){
            int nxt_node = i.first;
            int nxt_dist = i.second;


            //도로롤 포장하지 않고 갱신
            if(cur_dist + nxt_dist < dist[nxt_node][cur_pave]){
                dist[nxt_node][cur_pave] = cur_dist + nxt_dist;
                pq.push({-dist[nxt_node][cur_pave],{nxt_node,cur_pave}});
            }

            //도로 포장 가능할때
            if (cur_pave < K && dist[nxt_node][cur_pave + 1] > cur_dist) {
                dist[nxt_node][cur_pave + 1] = cur_dist;
                pq.push({-dist[nxt_node][cur_pave + 1], {nxt_node, cur_pave + 1}});
            }
        }
    }
}
int main(){
    First

    cin >> N >> M >> K;

    for(int i=1; i<=M; i++){
        cin >> srt >> ed >> num;
        v[srt].push_back({ed,num});
        v[ed].push_back({srt,num});
    }

    dijkstra();

    long long ans = INF;

    for(int i=0; i<=K; i++){
        ans = min(ans,dist[N][i]);
    }

    cout << ans << "\n";

}
