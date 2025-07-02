#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
typedef long long ll;
struct app{
    int byte;
    int cost;
};

ll dp[10001]; //i비용일때 가능한 최대 메모리

int N,M;
int a[101];
int b[101];
vector<app> v;
int main(){
    First
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> a[i];
    }
    int total_cost = 0;
    for(int i=0; i<N; i++){
        cin >> b[i];
        total_cost += b[i];
    }
    for(int i=0; i<N; i++){
        v.push_back({a[i],b[i]});
    }

    for(int i=0; i<=total_cost; i++){
        dp[i] = 0;
    }

    for(int i=0; i<N; i++){

        for(int j=total_cost; j>=v[i].cost; j--){
            dp[j] = max(dp[j], dp[j-v[i].cost] + v[i].byte);
        }
    }

    for(int i=0; i<=total_cost; i++){
        if(dp[i] >= M){
            cout << i << "\n";
            break;
        }
    }
}