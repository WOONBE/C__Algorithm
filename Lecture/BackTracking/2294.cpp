#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define INF 987654321

vector<int> arr;
int n,k;

int dp[10001]; //i를 만드는데 최소로 드는 동전 개수
int main(){

    cin >> n >> k;

    arr.resize(n);


    for(int i=0; i<n;i++){
        cin >> arr[i];
    }
//    dp[0] = 1;

    fill(dp, dp + 10001, INF);
    dp[0] = 0; // 0원을 만들기 위한 동전 개수는 0개




    //마지막에 arr[i]을 넣으면 됨
    for(int i=0; i<n; i++){
        for(int j=arr[i]; j<=k; j++){
            dp[j] = min(dp[j], dp[j-arr[i]] + 1);
        }
    }
    // 1 1, 2 1 1 ....

    if(dp[k] == INF){
        cout << -1 << "\n";
    }else{
        cout << dp[k] << "\n";
    }



}