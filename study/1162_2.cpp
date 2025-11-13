#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
int N,M,K,a,b,c;

vector<pair<ll,ll>> v[10001]; //i에서 j까지가는 비용이 k
ll dist[10001][21]; //i노드까지 j번 공사해서 가는 최소 비용
#define INF 9999987654321
ll answer = INF;
//다익스트라 활용
void dijkstra(){
    //i cost, j paved, k node까지
    priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<>> pq;
    pq.push({0,{0,1}});
    dist[1][0] = 0;
    while(!pq.empty()){
        auto cur = pq.top();pq.pop();

        auto cur_cost = cur.first;
        auto cur_paved = cur.second.first;
        auto cur_node = cur.second.second;
        if(dist[cur_node][cur_paved] < cur_cost) continue;

        for(auto nxt : v[cur_node]){
            auto nxt_node = nxt.first;
            auto nxt_cost = nxt.second;

            if(dist[nxt_node][cur_paved] > dist[cur_node][cur_paved] + nxt_cost){
                dist[nxt_node][cur_paved] = dist[cur_node][cur_paved] + nxt_cost;
                pq.push({dist[nxt_node][cur_paved],{cur_paved,nxt_node}});
            }
            //포장 가능하면
            if(cur_paved < K){
                //기존보다 포장 비용이 더 적으면
                if(dist[nxt_node][cur_paved+1] > dist[cur_node][cur_paved]){
                    dist[nxt_node][cur_paved+1] = dist[cur_node][cur_paved];
                    pq.push({dist[nxt_node][cur_paved+1],{cur_paved+1,nxt_node}});
                }

            }
        }
    }
}

int main(){
    First
    cin >> N >> M >> K;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=1; i<=N; i++){
        fill(dist[i],dist[i]+K+1,INF);
    }
    dijkstra();

    for(int i=0; i<=K; i++){
        answer = min(answer,dist[N][i]);
    }
    cout << answer << "\n";
}