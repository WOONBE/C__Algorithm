#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,m;
int dp[101][101];
vector<pair<int,int>> adj[101];
int degree[101];
int main(){
    First
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        adj[b].push_back({a,c});
        degree[a]++;
    }

    queue<int> q;
    for(int i=1; i<=n; i++){
        if(degree[i] == 0){
            q.push(i);
            dp[i][i] = 1;
        }
    }

    while(!q.empty()){
        int x = q.front(); q.pop();
        for(auto i : adj[x]){
            int nx = i.first;
            int cnt = i.second;

            for(int i=1; i<=n; i++){
                dp[nx][i] += dp[x][i] * cnt;

            }
            degree[nx]--;
            if(degree[nx] == 0){
                q.push(nx);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(dp[n][i] > 0){
            cout << i << ' ' << dp[n][i] << "\n";
        }
    }
    return 0;
}