#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 9987654321
int N,T,K,num,a,b;
int arr[501][501], dp[501][501];;
int main(){

    First

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> arr[i][0] >> arr[i][1];
    }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N-i; j++){
                dp[j][i+j] = INF;
                for(int k=j; k<i+j; k++){
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + arr[j][0] * arr[k][1] * arr[i+j][1]);
                }
            }
        }

        cout << dp[1][N] << "\n";

}