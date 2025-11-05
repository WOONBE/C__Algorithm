#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int cost[16][16];
int dp[1<<16]; //해당 마스크 상태가 되는 최소 비용
string s;
const int INF = 987654321;
int N,P,state;
int init_mask = 0;
int init_cnt = 0;
int ans = INF;//찾는 최소 cost
int main(){
    First
    cin >> N;
    for(int i=0;i<N; i++){
        for(int j=0; j<N; j++){
            cin >> cost[i][j];
        }
    }
    cin >> s;
    cin >> P;
    state = (1<<N);
    fill(dp,dp+state,INF);

    for(int i=0; i<N; i++){
        if(s[i] == 'Y'){
            init_mask |= (1<<i);
            init_cnt++;
        }
    }
    //초기 마스크 상태는 비용 x
    dp[init_mask] = 0;

    for(int mask = 0; mask < state; mask++){
        if(dp[mask] == INF) continue;

        for(int j=0; j<N; j++){
            int min_cost = INF;
            //j가 꺼진 발전소면 켜진 i번 발전소를 경유해서 on(i,j)
            if(!(mask & (1<<j))){
                for(int i=0; i<N; i++){
                    if(mask & (1<<i)){
                        min_cost = min(min_cost,cost[i][j]);
                    }
                }
            }
            //켤 방법이 있으면
            if(min_cost != INF){
                int nxt_mask = mask | (1<<j);
                dp[nxt_mask] = min(dp[nxt_mask],dp[mask] + min_cost);
            }
        }
    }
    //최소 cost find
    for(int mask = 0; mask < state; mask++){
        if(__builtin_popcount(mask)>=P){
            ans = min(ans,dp[mask]);
        }
    }
    if(ans == INF){
        cout << -1 << "\n";
    }else{
        cout << ans << "\n";
    }
    return 0;
}