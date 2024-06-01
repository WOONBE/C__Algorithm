#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> arr;
int dp[1001];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }

    sort(arr.begin(),arr.end());

    dp[0] = arr[0];

    int sum = arr[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + arr[i];
        sum += dp[i];
    }
    cout << sum;


}
