//
// Created by 김헌우 on 2024/09/14.
//2961
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int n;
vector<vector<long long >> v;
vector<int> visited;
long long min_sub = 987654321;

//신맛 짠맛 차이 계산하여 체크

//신맛 짠맛 조합 다 구하는 함수
void dfs(int idx, int cnt, long long sin, long long ssun){

    if(cnt >= 1){
        min_sub = min(min_sub, abs(sin - ssun));
    }

    for(int i=idx; i<n; i++){
        if(visited[i]) continue;
//        cnt++;
//        visited[i] = 1;
        dfs(i+1,cnt+1,sin * v[i][0], ssun + v[i][1]); //이부분 idx+1로 해서 터짐
//        visited[i] = 0; //visited는
    }
}

int main(){

    First
    cin >> n;
    v.resize(n, vector<long long >(2)); //초기화도 쓴맛 신맛이 끝이므로 2로 초기화가 맞음
    visited.resize(n);

    //long long 으로 받아야 안터질듯
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1]; //받는 것도 이차원 배열로 받는게 편한듯
    }

    dfs(0,0,1,0);

    cout << min_sub << "\n";
}
