#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int T,N,K,X,Y,W;

void solve(){
    cin >> N >> K;
    vector<int> tme(N + 1, 0);
    vector<int> graph[N + 1];
    vector<ll> dp(N + 1, 0); // 각 건물의 최종 완료 시간을 저장할 DP 배열
    vector<int> degree(N + 1, 0);

    for(int i = 1; i <= N; i++){
        cin >> tme[i];
    }
    for(int i = 0; i < K; i++) {
        cin >> X >> Y;
        graph[X].push_back(Y);
        degree[Y]++;
    }
    cin >> W;

    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(degree[i] == 0){
            q.push(i);
            dp[i] = tme[i];
        }
    }

    while(!q.empty()){
        int cur_node = q.front();
        q.pop();

        for(int nxt_node : graph[cur_node]){
            // 다음 건물의 완료 시간 = max(기존 계산된 완료 시간, 현재 건물을 거쳐 짓는 시간)
            dp[nxt_node] = max(dp[nxt_node], dp[cur_node] + tme[nxt_node]);

            degree[nxt_node]--;
            if(degree[nxt_node] == 0){
                q.push(nxt_node);
            }
        }
    }
    cout << dp[W] << "\n";
}

int main(){
    First
    cin >> T;
    while(T--){
        solve();
    }
}