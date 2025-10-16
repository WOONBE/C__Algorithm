#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;
int dp[100001];
int N,K,a,b;
int mx_val = 0;
int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> a >> b;
        v.push_back({a,b});
    }

    for(int i=0; i<N; i++){
        int cur_weight = v[i].first;
        int cur_val = v[i].second;

        for(int j=K; j>=cur_weight; j--){
            if(j-cur_weight>=0){
                dp[j] = max(dp[j],dp[j-cur_weight]+cur_val);
            }
        }
    }
    for(int i=K; i>=0; i--){
        if(dp[i]>mx_val){
            mx_val = dp[i];
        }
    }
    cout << mx_val << "\n";
}