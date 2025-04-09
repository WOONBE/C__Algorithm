#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int dp[10001]; // i무게일때 가질 수 있는 최대 만족도
int N, M, V, C, K;

int main(){
    First

    cin >> N >> M;

    vector<pair<int, int>> items;

    for(int i = 0; i < N; i++){
        cin >> V >> C >> K;

        // 이진 분해해서 K개를 O(log K)개의 아이템으로 쪼갬
        int cnt = 1;
        while(K > 0){
            int use = min(cnt, K);
            items.push_back({V * use, C * use});
            K -= use;
            cnt *= 2;
        }
    }

    for(auto [weight, value] : items){
        for(int i = M; i >= weight; i--){
            dp[i] = max(dp[i], dp[i - weight] + value);
        }
    }

    cout << dp[M] << "\n";
    return 0;
}
