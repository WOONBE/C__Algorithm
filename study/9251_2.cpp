#include <bits/stdc++.h>

using namespace std;
string a,b;
int dp[1001][1001]; //a는 i 인덱스일때, b는 j 인덱스일때 최대 길이
int main(){
    cin >> a >> b;

    for(int i=1; i<=a.length(); i++){
        for(int j=1; j<=b.length(); j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[a.length()][b.length()] << "\n";
}