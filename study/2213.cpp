#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int n,num,a,b;

int dp[10001][2]; //n노드가 인접한 정점 x or ㅇ
int cost[10001];
vector<int> adj[10001];
int mx_val = 0;
vector<int> ans;
int visited[10001];

void dfs(int cur){
    visited[cur] = 1;
    dp[cur][0] = 0;
    dp[cur][1] = cost[cur];

    for(int nxt : adj[cur]){
        if(visited[nxt]) continue;
        dfs(nxt); //실수
        dp[cur][0] += max(dp[nxt][0],dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }

}

void trace(int cur, bool is_in){
    visited[cur] = true;

    if(!is_in && dp[cur][1] > dp[cur][0]){
        ans.push_back(cur);
        for(int nxt : adj[cur]){
            if(!visited[nxt]){
                trace(nxt,true);
            }
        }
    }else{
        for(int nxt : adj[cur]){
            if(!visited[nxt]){
                trace(nxt,false);
            }
        }
    }
}
int main(){
    First
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> cost[i];
    }
    for(int i=0; i<n-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);

    memset(visited,0,sizeof(visited));
    trace(1,false);

    cout << max(dp[1][0],dp[1][1]) << "\n";

    sort(ans.begin(),ans.end());

    for(auto i : ans){
        cout << i << ' ';
    }cout << "\n";

    return 0;

}