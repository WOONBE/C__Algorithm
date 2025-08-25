#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N,a,b;
vector<int> people;
vector<int> adj[10001];
int dp[10001][2];

void dfs(int cur, int prev){

    dp[cur][0] = 0;
    dp[cur][1] = people[cur];

    for(auto nxt : adj[cur]){
        if(nxt == prev) continue;

        dfs(nxt,cur);
        dp[cur][0] += max(dp[nxt][0], dp[nxt][1]);
        dp[cur][1] += dp[nxt][0];
    }
}
int main(){
    First

    cin >> N;
    people.assign(N+1,0);
    for(int i=1; i<=N; i++){
        cin >> people[i];
    }
    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);

    cout << max(dp[1][0],dp[1][1]) << "\n";
    return 0;
}