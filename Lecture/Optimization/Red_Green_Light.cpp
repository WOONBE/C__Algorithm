//
// Created by 김헌우 on 2024/09/02.
//15736
//그려보면 본인 약수를 만나면 수가 바뀜 -> 제곱수를 리턴(제곱수는 특정수에 루트를 때리면 모든 경우의 수를 알 수 있음)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n;
int main(){
    First


    cin >> n;
//    vector<int> v(n,1); 여기서 메모리 초과
    //출력은 1 cnt

    int num = int(sqrt(n));
    cout << num << "\n";

}
