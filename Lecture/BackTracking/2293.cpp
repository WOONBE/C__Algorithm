#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//중복 조합같음
int n,k;
vector<int> arr;
int dp[10001]; //i일때의 경우의 수
void dfs(int value){

    if(value == k){
        return;
    }
}
int main(){
    First

    cin >> n >> k;
    arr.resize(n);

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
//    memset(dp,-1,sizeof(dp));

    dp[0] = 1;//이거부터 실수

    for(int i=0; i<n; i++){
        //arr[i]보다 작은값은 볼 필요가 없다
        for(int j = arr[i]; j<=k; j++){
//            dp[j] += dp[j-arr[i]];
            dp[j] = max(dp[j], dp[j] + dp[j-arr[i]]);
        }
    }




    cout << dp[k] << "\n";

}
