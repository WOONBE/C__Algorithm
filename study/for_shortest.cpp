#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

vector<tuple<int,int,int>> v;
int N,M,a,b,c,from,to,cost;
long long dist[501];

bool bellman(int x){
    dist[x] = 0;
    for(int i=1; i<N; i++){
        for(auto j : v){
            tie(from,to,cost) = j;
            if(dist[from] == 987654321) continue;
            if(dist[to] > dist[from] + cost) {
                dist[to] = dist[from] + cost;
            }
        }
    }
    for(auto i : v){
        tie(from,to,cost) = i;
        if(dist[from] == 987654321) continue;
        if(dist[to] > dist[from] + cost) {
            return true;
        }
    }
    return false;
}

int main(){
    First
    cin >> N >> M;
    for(int i=0; i<M; i++){
        cin >> a >> b >> c;
        v.emplace_back(a,b,c);
    }
    fill(dist,dist+501,987654321);

    bool hasCycle = bellman(1);

    if(hasCycle){
        cout << -1 << "\n";
    }else{
        for(int i=2; i<=N; i++){
            if(dist[i] == 987654321){
                cout << -1 << "\n";
            }else{
                cout << dist[i] << "\n";
            }
        }
    }
    return 0;
}
