#include <bits/stdc++.h>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0);
bool dp[40001]; //i일때 올릴수 있는지 여부(작게하면 터짐)
int N,weight,N_weight[501], M; //n는 무게추,m은 구슬
vector<int> M_weight;
int total_weight = 0;
int main(){
    First
    memset(dp,false,sizeof(dp));

    cin >> N;
    dp[0] = true;
    for(int i=0; i<N; i++){
        cin >> weight;
//        if(!dp[weight]) dp[weight] = true;
        N_weight[i] = weight;
        total_weight += weight;
    }
    cin >> M;
    M_weight.assign(M,0);
    for(int i=0; i<M; i++){
        cin >> M_weight[i];
    }
    for(auto w : N_weight){
        vector<int> possible_weight; //현재 추로 가능한 무게들

        for(int i=0; i<=total_weight; i++){//가능한 무게들 넣기
            if(dp[i]){
                possible_weight.push_back(i+w);
                possible_weight.push_back(abs(i-w));
            }
        }
        for(auto j : possible_weight){//넣은 무게들로 dp테이블 갱신
            if(!dp[j]){
                dp[j] = true;
            }
        }
    }
    for(auto i : M_weight){
        if(dp[i]) cout << 'Y' << ' ';
        else  cout << 'N' << ' ';
    }
}