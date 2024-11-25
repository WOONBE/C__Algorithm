#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MX 9987654321

int N,M;
vector<pair<long long , long long>> adj[1001];
int start_num, end_num;

vector<int> pre(1001, 0);

long long dijkstra(int start){
    vector<long long> dist(N+1, MX);
    priority_queue<pair<long long,long long>, vector<pair<long long ,long long >>, greater<>> pq;

    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        auto [cur_cost, cur_city] = pq.top(); pq.pop();

        if(dist[cur_city] < cur_cost) continue;

        for(auto [nxt_cost, nxt_city] : adj[cur_city]){
            nxt_cost = nxt_cost + cur_cost;
            if(nxt_cost < dist[nxt_city]){
                dist[nxt_city] = nxt_cost;
                pre[nxt_city] = cur_city;
                pq.push({nxt_cost,nxt_city});
            }
        }
    }
    return dist[end_num];
}

vector<int> find_path(int start, int end) {
    vector<int> path;
    for (int cur = end; cur != start; cur = pre[cur]) {
        path.push_back(cur);
    }
    path.push_back(start); // 마지막으로 시작점을 추가
    reverse(path.begin(), path.end()); // 역순으로 저장했으므로 뒤집기

    return path;
}



int main(){
    First
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int start,end,cost;
        cin >> start >> end >> cost;
        adj[start].push_back({cost,end});
    }
    cin >> start_num >> end_num;



    cout << dijkstra(start_num) << "\n";
    vector<int> path = find_path(start_num, end_num);
    cout << path.size() << "\n";
    for(auto i : path){
        cout << i << ' ';
    }cout << "\n";


}