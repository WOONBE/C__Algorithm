#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
int n,m,a,b,cost,srt,dest;
ll dp[10001]; //i노드까지 시간
vector<pair<int,int>> v[10001];
vector<pair<int,int>> v1[10001];
int degree[10001];
int visited[10001] = {0,};
queue<pair<int,int>> q; //노드번호,시간
int main(){
    First
    cin >> n;
    cin >> m;
    fill(dp,dp+n+1,0);
    for(int i=0; i<m; i++){
        cin >> a >> b >> cost;
        v[a].push_back({b,cost});
        v1[b].push_back({a,cost});
        degree[b]++;
    }
    cin >> srt >> dest; //이거 별로 상관없음

    q.push({srt,0});
    dp[srt] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cur_node = cur.first;
        for(auto nxt : v[cur_node]){
            int nxt_node = nxt.first;
            ll nxt_tme = dp[cur_node] + nxt.second;
            dp[nxt_node] = max(dp[nxt_node],nxt_tme);
            degree[nxt_node]--;
            if(!degree[nxt_node]){
                q.push({nxt_node,nxt_tme});
            }
        }
    }
    cout << dp[dest] << "\n";

    queue<int> trace;
    //역방향으로 돌리면서 dp의 값이랑 비교
    trace.push(dest);
    visited[dest] = 1;
    int cnt = 0;
    while(!trace.empty()){
        int cur_node = trace.front();trace.pop();
        for(auto nxt : v1[cur_node]){
            int nxt_node = nxt.first;
            ll nxt_dist = nxt.second;

            if(dp[nxt.first] + nxt_dist == dp[cur_node]){
                cnt++;
                if(!visited[nxt_node]){
                    visited[nxt_node] = 1;
                    trace.push(nxt_node);
                }
            }
        }
    }
    cout << cnt << "\n";


}