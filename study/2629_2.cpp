#include <bits/stdc++.h>

using namespace std;

int weight[31];//구슬 무게들
int check_num[7]; //확인할 무게

bool is_possible[40001]; //i무게가 확인 가능한지
int N,M,mx_weight;
int main(){

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> weight[i];
        mx_weight += weight[i];
    }
    cin >> M;

    for(int i=0; i<M; i++){
        cin >> check_num[i];
    }

    is_possible[weight[0]] = true;

    //배열 돌면서 is_possible 체크
    for(int i=1; i<N; i++){
        set<int> possible_weight;
        int cur_weight = weight[i];

        for(int j=mx_weight; j>=0; j--) {
            if (is_possible[j]) {
                possible_weight.insert(abs(cur_weight + j));
                possible_weight.insert(abs(cur_weight - j));
            }
        }
        if(!is_possible[cur_weight]){
            possible_weight.insert(cur_weight);
        }
        for(auto k : possible_weight){
            if(!is_possible[k]){
                is_possible[k] = true;
            }
        }
    }
    for(int i=0; i<M; i++){
        if(is_possible[check_num[i]]){
            cout << 'Y' << ' ';
        }else{
            cout << 'N' << ' ';
        }
    }cout << "\n";
}