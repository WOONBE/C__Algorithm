#include <iostream>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int arr[1001][1001];
int dp[1001][1001];
int temp[1001][1001][2];
int N, M;

int main(){
    First

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j-1] + arr[0][j];
    }

    // 두 번째 행부터
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = dp[i-1][j] + arr[i][j];
        }

        temp[i][0][0] = dp[i][0];
        for (int j = 1; j < M; j++) {
            temp[i][j][0] = max(temp[i][j-1][0] + arr[i][j], dp[i][j]);
        }

        temp[i][M-1][1] = dp[i][M-1];
        for (int j = M-2; j >= 0; j--) {
            temp[i][j][1] = max(temp[i][j+1][1] + arr[i][j], dp[i][j]);
        }

        for (int j = 0; j < M; j++) {
            dp[i][j] = max(temp[i][j][0], temp[i][j][1]);
        }
    }

    cout << dp[N-1][M-1] << '\n';

    return 0;
}
