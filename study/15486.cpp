#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int N,day,cost;
vector<pair<int,int>> v;

int dp[1500001]; //날짜에 얻을 수 있는 최대 수익

int dfs(int day){

    if(day >= N){
        return 0;
    }
    if(dp[day] != -1){
        return dp[day];
    }

    int not_consult = dfs(day+1); //이 부분 실수
    int has_consult = 0;
    if(day + v[day].first <=N){
        has_consult = dfs(day + v[day].first) + v[day].second;
    }
    dp[day] = max(not_consult,has_consult);
    return dp[day];
}




int main(){
    First

    cin >> N;

    memset(dp,-1,sizeof(dp));

    for(int i=0; i<N; i++){
        cin >> day >> cost;
        v.push_back({day,cost});
    }

    cout << dfs(0) << "\n";




}