//
// Created by 김헌우 on 2024/06/12.
//

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
// 벡터 a의 부분합 계산
vector<int> partialSum(const vector<int>& a){
    vector<int> ret(a.size());
    ret[0] = a[0];
    for(int i=1; i<a.size(); i++){
        ret[i] = ret[i-1] + a[i];
    }
    return ret;
}

//부분합이 주어질때 벡터 a에서 b까지의 합 계산
int rangeSum(const vector<int>& psum, int a, int b){
    if(a==0) return psum[b];
    return psum[b] - psum[a-1]; //이 부분이 중요
}

int main(){


        vector<int> scores = { 100,97,86,79,66,52,49 };
        vector<int> psum(scores.size());

        partial_sum(scores.begin(), scores.end(), psum.begin());

        for (auto& x : psum) cout << x << " ";


}
