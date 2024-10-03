#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s1,s2;
int dp[1001][1001];
int main(){
    First
    cin >> s1 >> s2;



    for(int i=1; i<=s1.length(); i++){
        for(int j=1; j<=s2.length(); j++){
            if(s1[i-1] == s2[j-1]){ //이부분 인덱스 잘못 설정
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout << dp[s1.length()][s2.length()];

}