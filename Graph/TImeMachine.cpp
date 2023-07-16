//
// Created by 김헌우 on 2023/07/16.
//벨만 포드 사용해서 풀이(가중치가 음수)
#include "bits/stdc++.h"
using namespace std;
const long long INF = 1e9;
vector<pair<int,int>> v[501];
bool cycle;
int n,m; //노드 n, 간선 m
int a,b,c;
long long dis[10000]; //int로 해놔서 계속 출력초과 떴었음

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }

    for(int i =1; i<=n;i++) //Bellman-Ford 사용시 다 무한대에서 시작함
        dis[i] = INF;
//    fill(dis,dis+n+1,INF);
    dis[1] = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 0; k < v[j].size(); k++) //v-1번 돌면 최단거리 갱신함, v번 돌면 음수의 간선 있는지 여부 파악 가능
            {
                int next = v[j][k].first; //다음 노드 선택
                int d = v[j][k].second; //그 거리 선택

                if (dis[j] != INF && dis[next] > dis[j] + d)
                {
                    dis[next] = dis[j] + d;
                    if (i == n) cycle = true;
                }

            }
        }

    if (cycle) cout << -1 << '\n';
    else
    {
        for (int i = 2; i <= n; i++)
            cout << (dis[i] != INF ? dis[i] : -1) << '\n';
    }

}


