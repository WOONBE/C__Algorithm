#include <iostream>
#include <cstring>
using namespace std;

int n;
long long dp[101]; //long long 안해주면 틀림
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int tc=1; tc<=T; tc++){
        cin >> n;

        memset(dp,0,sizeof(dp));

        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 1;
        dp[4] = 2;
        dp[5] = 2;

        for(int i=6; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-5];
        }
        cout << dp[n] << "\n";
    }
}
