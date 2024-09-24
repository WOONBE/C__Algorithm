//
//6%에서 시간초과
//12865

#include <iostream>
#include <vector>

using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n,k;

vector<vector<int>> v;

int max_value = 0;
void dfs(int idx, int weight, int value){

//    if(weight >= k){
//        max_value = max(value, max_value);
//        return;
//    }
//    dfs(idx+1, weight, value);
//
//    if(v[idx][0] + weight <= k && idx<=n){
//        dfs(idx+1, weight + v[idx][0], value + v[idx][1]);
//    }
    //같거나 작을때가 아니라 그냥 클때 리턴
    if (weight > k) {
        return; // 현재 무게가 배낭의 최대 무게를 초과하면 종료
    }
     // 최대 가치 업데이트

    //이부분 처리를 안했음
    if (idx >= n) {
        max_value = max(max_value, value);
        return; // 모든 물건을 고려한 경우 종료
    }

    // 현재 물건을 배낭에 넣지 않는 경우
    dfs(idx + 1, weight, value);

    // 현재 물건을 배낭에 넣는 경우
    if(weight + v[idx][0] <= k){
        dfs(idx + 1, weight + v[idx][0], value + v[idx][1]);
    }

}
void input(){
    cin >> n >> k;

    v.resize(n,vector<int>(2));
    for(int i=0; i<n; i++){
        cin >> v[i][0] >> v[i][1];
    }
}

int main(){
    First
    input();
    dfs(0,0,0);

    cout << max_value << "\n";

}
