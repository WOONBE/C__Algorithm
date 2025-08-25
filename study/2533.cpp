#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int N,a,b;
vector<int> adj[1000001];
int dp[1000001][2];

void dfs(int cur, int prev){

    dp[cur][0] = 0; //얼리어답터가 아닐때
    dp[cur][1] = 1; //자기 자신이 얼리어답터일때

    for(auto nxt : adj[cur]){
        if(nxt == prev) continue;

        dfs(nxt,cur);//말단 노드로 go

        //얼리어답터가 아니면 -> 이전 노드는 반드시 얼리어답터
        dp[cur][0] += dp[nxt][1];
        //얼리어답터인 경우 -> 이전 노드는 얼러어답터거나 아니어도 무방
        dp[cur][1] += min(dp[nxt][0],dp[nxt][1]);
    }
}

int main(){
    First
    cin >> N;

    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1,0);

    cout << min(dp[1][0],dp[1][1]) << "\n";
    return 0;
}