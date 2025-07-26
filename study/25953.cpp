#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
int n,t,m,srt,ed,X,Y,Z;
ll dp[1001][10001]; //i년도일때 j노드에 가는 최소거리
const ll INF = 1e18;

int main(){
    First
    cin >> n >> t >> m;
    cin >> srt >> ed;
    for(int i=0; i<n; i++){
        dp[0][i] = INF;
    }
    dp[0][srt] = 0;
    for(int tme = 0; tme < t; tme++){

        for(int i=0; i<n; i++){
            dp[tme+1][i] = dp[tme][i];
        }
        for(int i=0; i<m; i++) {
            cin >> X >> Y >> Z;
            dp[tme + 1][Y] = min(dp[tme + 1][Y], dp[tme][X] + Z);
            dp[tme + 1][X] = min(dp[tme + 1][X], dp[tme][Y] + Z);
        }
    }
    if(dp[t][ed] == INF) cout<< -1 << "\n";
    else cout << dp[t][ed] << "\n";
    return 0;
}