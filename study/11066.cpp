#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 9987654321
int T,K,num;
int sum[501], file[501], dp[501][501];
int main(){

    cin >> T;

    while(T--){
        cin >> K;

        memset(sum,0,sizeof(sum));
        memset(file,0,sizeof(file));
        memset(dp,0,sizeof(dp));

        for(int i=1; i<=K; i++){
            cin >> file[i];
            sum[i] = sum[i-1] + file[i];
        }

        for(int i=1; i<=K; i++){
            for(int j=1; j<=K-i; j++){
                dp[j][i+j] = INF;
                for(int k=j; k<i+j; k++){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }

        cout << dp[1][K] << "\n";
    }
}