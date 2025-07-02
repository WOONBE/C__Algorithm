#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int T,N;
int dp[1001][1001];
vector<int> v;

int play(int l, int r, int turn){
    if(l>r)return 0;
    if(dp[l][r] != -1) return dp[l][r];

    if(turn % 2 == 1){
        dp[l][r] = max((v[l] + play(l+1,r,turn+1)),v[r] + play(l,r-1,turn+1));
    }else{
        dp[l][r] = min(play(l+1,r,turn+1),play(l,r-1,turn+1));
    }
    return dp[l][r];
}

int main(){
    First
    cin >> T;

    while(T--){
        cin >> N;

        memset(dp,-1,sizeof(dp));
        v.assign(N,0);
        for(int i=0; i<N; i++){
            cin >> v[i];
        }
        play(0,N-1,1);

        cout << dp[0][N-1] << "\n";
    }

}