#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
#define MOD 1000000003
typedef long long ll;
int N,K;
vector<vector<int>> dp;
int main(){
    cin >> N;
    cin >> K;
    dp.resize(N+1, vector<int>(K+1));
    if(K == 1){
        cout << N << "\n";
        return 0;
    }
    if(K > N/2){ //뽑는게 절반 이상이면 무조건 인접
        cout << 0 << "\n";
        return 0;
    }
    //안뽑거나 하나만 뽑는 경우의 수
    for(int i=0; i<=N; i++){
        dp[i][0] = 1;
    }
    for(int i=1; i<=N; i++){
        dp[i][1] = i;
    }
    for(int i=3; i<=N; i++){
        for(int j=2; j<=K; j++){
            if(i < j*2 -1) continue;
            dp[i][j] = (dp[i-1][j] + dp[i-2][j-1]) % MOD; //현재 색 선택 안하는 경우 + 이미 현재 색을 선택한 경우
        }
    }

    ll ans = (dp[N-1][K] + dp[N-3][K-1]) % MOD; //1번 색을 안고르는 경우 + 1번색을 고르는 경우(2번,N번은 제외하고 선택)

    cout << ans << "\n";
    return 0;

}