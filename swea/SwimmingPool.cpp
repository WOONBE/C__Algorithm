//
// Created by 김헌우 on 2024/03/07.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int ans, day, month, three_month, year;
int plan[13];
int dp[13];


void init(){
    ans = 0;
    memset(dp,0,sizeof(dp));


}
void input(){
    cin >> day >> month >> three_month >> year;
    for(int i=1; i<13; i++){
        cin >> plan[i];
    }

}
void solve(){
    dp[1] = min((day*plan[1]), month);
    dp[2] = min(dp[1] +(day*plan[2]), dp[1] + month);
    for(int i=3; i<=12; i++){
        dp[i] = min({dp[i-1] + day*plan[i], dp[i-1] + month,dp[i-3]+three_month});
    }
    if(dp[12] > year){
        dp[12] = year;
    }
}
int main(){
    int t;
    cin >> t;
    for(int tc=1; tc<=t; tc++){
        init();
        input();
        solve();

        cout << '#' << tc << ' ' <<  dp[12] << "\n";

    }





}
