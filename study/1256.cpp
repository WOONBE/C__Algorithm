#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
#define INF 1987654321
ll dp[201][101]; //총 n개중에 r개를 고르는 경우의 수
ll N,M,K;

ll make_comb(int n, int r){
    if(n==r || r==0) return 1;

    if(dp[n][r] != -1) return dp[n][r];

    ll left = make_comb(n-1,r-1);

    ll right = make_comb(n-1,r);

    if(left + right > 1000000000) return dp[n][r] = INF;
    return dp[n][r] = left + right;

}

void go(int n, int m, ll rest) {
    if (ll c = make_comb(n + m - 1, n - 1); n > 0 && rest <= c) {
        cout << 'a';
        go(n - 1, m, rest);
    } else if (m > 0) {
        cout << 'z';
        go(n, m - 1, rest - c);
    }
}
int main(){
    First
    memset(dp,-1,sizeof(dp));

    cin >> N >> M >> K;

    if(make_comb(N+M, N) < K){
        cout << -1;
        return 0;
    }
    go(N, M, K);
}