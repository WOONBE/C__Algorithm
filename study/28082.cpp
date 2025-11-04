#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);

int N,K;
vector<int> v;
int dp[250001];//i배터리를 만드는데 필요한 배터리 개수,마지막에 1이상 k이하로 제한 걸어줌
set<int> s;
int mx_bat = 0;
int main(){
    First

    cin >> N >> K;
    v.assign(N,0);
    for(int i=0; i<N; i++){
        cin >> v[i];
        mx_bat += v[i];
    }
    sort(v.begin(),v.end());

    fill(dp,dp+mx_bat+1,K+1); //fill vs memset

    dp[0] = 0;

    for(int i=0; i<N; i++){
        for(int j=mx_bat; j>=v[i]; j--){
            dp[j] = min(dp[j],dp[j-v[i]] + 1);

        }
    }

    for(int i=1; i<=mx_bat; i++){
        if(dp[i]>=1 && dp[i]<=K){
            s.insert(i);
        }
    }

    cout << s.size() << "\n";

    for(auto i : s){
        cout << i << ' ';
    }cout << "\n";

}