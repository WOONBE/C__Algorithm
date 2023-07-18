//
// Created by 김헌우 on 2023/07/17.
//플로이드 워셜 기본

#include "bits/stdc++.h"
using namespace std;
const int INF = 100000000;
int dis[101][101];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;

    cin >> n >> m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            if(i==j) dis[i][j] = 0;
            else dis[i][j] = INF;

    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b],c);
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){ //이부분 범위 잘못 설정해서 드럽게 오래 걸림
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            if(dis[i][j] == INF) cout << "0 ";
            else cout << dis[i][j]<< " ";
        cout << "\n";
    }return 0;
}
