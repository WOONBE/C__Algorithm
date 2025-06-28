#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
int dp[100001]; //i원을 만들 수 있는 경우의 수
int n,k;
vector<int> v;
int main(){
    First
    cin >> n >> k;
    v.assign(n,0);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    for(int i=0; i<n; i++){
        dp[v[i]] += 1;
        for(int j=v[i]; j<=k; j++){
            dp[j] += dp[j-v[i]];
        }
    }
    cout << dp[k] << "\n";
}