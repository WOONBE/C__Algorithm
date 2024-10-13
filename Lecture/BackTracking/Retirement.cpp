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

// 최대 수익을 구하는 DFS 함수
void dfs(int day, int price) {
    // 날짜가 N일을 넘으면 종료
    if (day >= n) {
        max_price = max(max_price, price);
        return;
    }

    // 상담을 하지 않고 다음 날로 넘어가는 경우
    dfs(day + 1, price);

    // 현재 날짜에 상담을 하는 경우
    if (day + v[day][0] <= n) {  // 상담이 N일 내에 끝나는지 확인
        dfs(day + v[day][0], price + v[day][1]);
    }
}

void input(){
    cin >> n;
    v.resize(n,vector<int>(2));
    visited.resize(n);
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1];
    }
}
int main(){
    First

    input();

    dfs(0,0);

    cout << max_price;

}