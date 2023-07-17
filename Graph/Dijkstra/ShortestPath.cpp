//
// Created by 김헌우 on 2023/07/17.
//다익스트라 알고리즘 활용, 초록책

#include "bits/stdc++.h"
using namespace std;

int v,e; //v노드 e 간선
int k; //시작점 번호
#define MAX 20010
typedef long long ll;
vector<pair<int,int>> adj[MAX]; //vector는 뒤에 정의 x시 원하는 위치에 in 불가

ll INF = 1e9;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    cin >> k;
    for(int i=1; i<=e; i++) {
        //간선 정보 받기
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
    }
//    for(int i=1; i<=v; i++)
//        dis[i] = INF;
    ll dis[MAX];//거리 저장
    int processed[MAX]; //처리여부 저장
    fill(dis,dis+MAX,INF);
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> >> q; //우선순위 큐 활용

    dis[k] = 0;

    q.push(make_pair(0,k));
    while (!q.empty()){
        int cur = q.top().second; q.pop();
        if(processed[cur]) break;
        processed[cur] = true;
        for(auto u : adj[cur]){
            int b = u.first, w = u.second;
            if(dis[cur]+ w < dis[b]){
                dis[b] = dis[cur] + w;
                q.push(make_pair(dis[b],b));
            }
        }
    }
    for(int i=1; i<=v; i++){
        if(dis[i] == INF) cout << "INF" << "\n";

        else cout << dis[i] << "\n";
    }return 0;
}
