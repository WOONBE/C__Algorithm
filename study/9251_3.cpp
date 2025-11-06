#include <bits/stdc++.h>
using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
string a,b;
int n,m;
int dp[1001][1001]; //a의 i번 글자 앞까지 봤을때, b의 j번 글자 앞까지 봤을때의 lcs 길이
int main(){
    First
    cin >> a;
    cin >> b;
    n = a.length();
    m = b.length();
    dp[0][0] = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            //두 글자가 같으면
            if(a[i-1] == b[j-1]){
                dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
}