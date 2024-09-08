//
// Created by 김헌우 on 2024/09/08.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int main(){

    int N,M;
    int height;

    cin >> N >> M;

    vector<int> trees(N,0);

    for(int i=0; i<N; i++){
        cin >> height;
        trees[i] = height;
    }
    sort(trees.begin(),trees.end());

//    for(auto i : trees){
//
//        cout << i << ' ';
//    }

    long long low_height = 0; //이부분 실수
    long long high_height = trees[N-1];
    long long ans = 0;
    while(low_height <= high_height){
        long long sum = 0;
        long long cut = (low_height+high_height) / 2;

        for(int i=0; i<N; i++){
            if(trees[i] - cut > 0){
                sum += trees[i] - cut;
            }
        }
        //이 밑의 조건문 자꾸 반복문 안에 넣는데 이거 좀 고치자(뭐하다 안되면 이거때문임)
        if(sum >= M){
            ans = cut;
            low_height = cut + 1;
        }
        else{
            high_height = cut - 1;
        }
    }

    cout << ans << "\n";


}