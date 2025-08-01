#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N,K;
int tme[100001];
const int INF = 1e9;
const int MAX = 100001;
void dijkstra(int node){
    //앞에 시간, 뒤에 노드번호
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<>> pq;
    pq.push({0,node});
    tme[node] = 0;

    while(!pq.empty()){
        auto cur_tme = pq.top().first;
        auto cur_node = pq.top().second;
        pq.pop();

        if (tme[cur_node] < cur_tme) {
            continue;
        }

        int next_node1 = cur_node - 1;
        if (next_node1 >= 0) {
            if (tme[next_node1] > cur_tme + 1) {
                tme[next_node1] = cur_tme + 1;
                pq.push({tme[next_node1], next_node1});
            }
        }

        int next_node2 = cur_node + 1;
        if (next_node2 < MAX) {
            if (tme[next_node2] > cur_tme + 1) {
                tme[next_node2] = cur_tme + 1;
                pq.push({tme[next_node2], next_node2});
            }
        }
        int next_node3 = cur_node * 2;
        if (next_node3 < MAX) {

            if (tme[next_node3] > cur_tme) {
                tme[next_node3] = cur_tme;
                pq.push({tme[next_node3], next_node3});
            }
        }
    }
}

int main(){
    First
    cin >> N >> K;
    fill(tme,tme+MAX,INF);
    dijkstra(N) ;

    cout << tme[K] << "\n";

}