//
// Created by 김헌우 on 2024/09/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
int max_price = 0;
vector<vector<int>> v;
vector<int> visited;
vector<int> dp;


// 최대 수익을 구하는 DFS 함수
int dfs(int day) {
    if (day >= n) {
        return 0;
    }

    // 이미 계산된 값이 있다면 그 값을 반환 (메모이제이션)
    if (dp[day] != -1) {
        return dp[day];
    }

    // 상담을 하지 않고 다음 날로 넘어가는 경우
    int withoutConsulting = dfs(day + 1);

    // 상담을 하고 다음 가능한 날짜로 넘어가는 경우 (상담이 가능한지 확인)
    int withConsulting = 0;
    if (day + v[day][0] <= n) {  // 상담이 n일 내에 끝나는지 확인
        withConsulting = dfs(day + v[day][0]) + v[day][1];
    }

    // 더 큰 값을 선택하여 dp에 저장
    dp[day] = max(withoutConsulting, withConsulting);

    return dp[day];

}

void input(){
    cin >> n;
    v.resize(n,vector<int>(2));
    visited.resize(n,-1);
    dp.resize(n,-1); //추가, 메모이제이션 사용하려고 -1로 초기화
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1];
    }
}
int main(){
    First

    input();

    cout << dfs(0);

}