#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
#define INF 1e9;
typedef long long ll;
int N;
vector<pair<int,int>> v;
ll dp[501][501];//i idx에서 j idx까지 곱한 곱셈 연산의 최솟값
int main(){
    First
    cin >> N;
    v.assign(N+1,{0,0});
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=N; i++){
        cin >> v[i].first >> v[i].second;
    }
    for(int i=1; i<=N; i++){ //한번에 곱할 범위
        for(int j=1; j<=N-i; j++){ //시작 인덱스
            dp[j][i+j] = INF;
            for(int k=j; k<=j+i; k++){ //중간값 지정
                dp[j][j+i] = min(dp[j][j+i],dp[j][k] + dp[k+1][j+i] + v[j].first * v[k].second * v[j+i].second);
            }
        }
    }
    cout << dp[1][N] << "\n";
}