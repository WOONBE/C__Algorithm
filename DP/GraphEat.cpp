//
// Created by 김헌우 on 2024/05/09.
//
#include <iostream>
#include <algorithm>

using namespace std;
int arr[10001];
int dp[10001];


int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }


    dp[0] = 0;
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for(int i=3; i<=n; i++){
        dp[i] = max({dp[i-3]+arr[i-1]+arr[i], dp[i-2]+arr[i], dp[i-1]});
    }

    cout << dp[n] << "\n";



}
