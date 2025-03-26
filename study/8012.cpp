#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,st,ed;
vector<int> node[30001];
bool visited[30001];
int d[30001];
int p[30001][18];
void dfs(int x){

    queue<int> q;
    visited[x] = true;
    q.push(x);

    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(auto i : node[cur]){
            if(visited[i]) continue;
            visited[i] = true;
            d[i] = d[cur] + 1;
            p[i][0] = cur;
            q.push(i);
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
        if(p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];

        }
    }
    return p[x][0];
}



int main(){
    First

    cin >> n;

    for(int i=0; i<n-1; i++){
        cin >> st >> ed;
        node[st].push_back(ed);
        node[ed].push_back(st);
    }
    dfs(1);

    for(int j=1; (1<<j)<n; j++){
        for(int i=1; i<=n; i++){
            if(p[i][j-1] !=0){
                p[i][j] = p[p[i][j-1]][j-1];
            }
        }
    }
    int M;

    cin >> M;
    long long ans = 0;
    int prev,now;
    for(int i=0; i<M; i++){
        cin >> now;
        if(i !=0){
            ans += d[prev] + d[now] - 2*(d[lca(prev,now)]);
        }
        prev = now;
    }

    cout << ans << "\n";

}