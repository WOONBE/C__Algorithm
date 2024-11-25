#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAX 9987654321
vector<pair<long long, long long >> v[1001];

int N,M;
int start_num, end_num;
long long dijkstra(int start){
    vector<long long> dist(N+1, MAX);

    //dist, node num
    priority_queue<pair<long long, int>, vector<pair<long long ,int>>, greater<>> pq;

    dist[start] =0;

    pq.push({0,start});

    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        long long cur_dist = cur.first;
        int cur_now = cur.second;

        if(dist[cur_now] < cur_dist) continue;

        for(auto i : v[cur_now]){
            int nxt_city = i.first; //순서 확실히 숙지
            long long nxt_dist = i.second;
            nxt_dist = cur_dist + nxt_dist;

            if(nxt_dist < dist[nxt_city]){
                dist[nxt_city] = nxt_dist;
                pq.push({nxt_dist,nxt_city});
            }
        }
    }
    return dist[end_num];


}
int main(){
    First

    cin >> N >> M;
    for(int i=0; i<M; i++){
        int start,end,cost;
        cin >> start >> end >> cost;
        v[start].push_back({end,cost});
    }
    cin >> start_num >> end_num;

    cout << dijkstra(start_num) << "\n";



}