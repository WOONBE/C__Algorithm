#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll INF = 9e18; // long long에 맞는 충분히 큰 값
int N,M;
int a,b,c;
int gas[2501];
// dist[도시][기름값] = 해당 상태의 최소 총비용
ll dist[2501][2501];
vector<pair<int,int>> v[2501]; // {연결된 노드, 도로 길이}

void dijkstra(int srt_node){
    // 튜플: {총 비용, 현재 노드, 현재까지의 최소 기름값}
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

    for(int i=0; i<=N; ++i){
        for(int j=0; j<=2500; ++j){
            dist[i][j] = INF;
        }
    }

    dist[srt_node][gas[srt_node]] = 0;
    pq.push({0, srt_node, gas[srt_node]});

    while(!pq.empty()){
        auto [cur_dist, cur_node, cur_min_gas] = pq.top();
        pq.pop();

        if (dist[cur_node][cur_min_gas] < cur_dist) {
            continue;
        }

        for(auto& edge : v[cur_node]){
            int nxt_node = edge.first;
            int road_len = edge.second;

            // 1. 다음 노드까지 이동했을 때의 총 비용 계산
            ll new_dist = cur_dist + (ll)road_len * cur_min_gas;

            // 2. 다음 노드에 도착했을 때의 새로운 '최소 기름값' 상태 계산
            int nxt_min_gas = min(cur_min_gas, gas[nxt_node]);

            // 3. (다음 노드, 새로운 최소 기름값) 상태로 가는 경로가 더 저렴하다면 갱신
            if(dist[nxt_node][nxt_min_gas] > new_dist){
                dist[nxt_node][nxt_min_gas] = new_dist;
                pq.push({new_dist, nxt_node, nxt_min_gas});
            }
        }
    }
}

int main(){
    First
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> gas[i];
    }
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
        v[b].push_back({a,c}); // 양방향 그래프
    }

    dijkstra(1);

    ll min_total_cost = INF;
    // N번 도시에 어떤 기름값 상태로든 도착한 모든 경우 중 최소 비용을 찾음
    for(int i = 1; i <= 2500; ++i){
        min_total_cost = min(min_total_cost, dist[N][i]);
    }

    cout << min_total_cost << "\n";
    return 0;
}