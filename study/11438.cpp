#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool visited[100001];
vector<int> v[100001];
int p[100001][18];
int d[100001];
int N,M;
queue<int> q;
void bfs(int x){
    visited[x] = true;
    q.push(x);

    while(!q.empty()){
        x = q.front(); q.pop();
        for(int nxt : v[x]){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            d[nxt] = d[x] + 1;
            p[nxt][0] = x;
            q.push(nxt);
        }
    }
}
int lca(int x, int y){
    if(d[x] < d[y]){
        swap(x,y);
    }
    for(int i=16; i>=0; i--){
        if(d[x] - (1<<i) >= d[y]){
            x = p[x][i];
        }
    }
    if(x==y) return x;

    for(int i=16; i>=0; i--){
        if(p[x][i] != p[y][i]){
            x = p[x][i];
            y = p[y][i];
        }
    }
    return p[x][0];
}



int main(){
    First

    cin >> N;
    for(int i=1; i<N;i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    bfs(1);

    for(int j=1; (1<<j) < N; j++){
        for(int i=1; i<=N; i++){
            if(p[i][j-1]){
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
    }
    cin >> M;
    for(int i=0; i<M; i++){
        int a,b;
        cin >> a >> b;
        cout << lca(a,b) << "\n";

    }





}