#include <bits/stdc++.h>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0);
#define INF 987654321;
int T,K, v[501],prefix[502], dp[501][501];//i idx에서 j idx까지의 합할때 최소비용
int main(){
    First
    cin >> T;

    while(T--){
        cin >> K;
        memset(v,0,sizeof(v));
        memset(dp,0,sizeof(dp));
        memset(prefix,0,sizeof(prefix));
        for(int i=1; i<=K; i++){
            cin >> v[i];
        }
        for(int i=1; i<=K; i++){
            prefix[i] = prefix[i-1] + v[i];
        }
        for(int i=1; i<=K; i++){ //한번에 몇개 더할지
            for(int j=1;j<=K-i;j++){//어느 인덱스부터 시작하는지
                dp[j][j+i] = INF;
                for(int k=j; k<=j+i; k++){ //둘 사이 중간값
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][j+i] + prefix[j+i] - prefix[j-1]);
                }
            }
        }
        cout << dp[1][K] << "\n";
    }
}
