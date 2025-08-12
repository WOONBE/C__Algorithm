#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
const int INF = 1e8;
int V,E,a,b,c,dist[401][401];
int main(){
    First
    cin >> V >> E;

    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            dist[i][j] = INF;
        }
    }


    for(int i=0; i<E; i++){
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
    }

    for(int k=1; k<=V; k++){
        for(int i=1; i<=V; i++){
            for(int j=1; j<=V; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = INF;
    for(int i=1; i<=V; i++){
        if(dist[i][i] < ans){
            ans = dist[i][i];
        }
    }

    if(ans == INF) cout << -1 << "\n";
    else cout << ans << "\n";
    return 0;


}