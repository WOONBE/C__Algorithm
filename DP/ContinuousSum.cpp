//
// Created by 김헌우 on 2024/02/13.
//

#include <iostream>
#include <algorithm>

int n;

int num[100001]; //100,000으로 설정하면 runtime error
int d[100001];
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> num[i];
    }
    for(int i = 1; i <= n; ++i)
        d[i] = max(0, d[i-1]) + num[i];
    cout << *max_element(d + 1, d + n + 1);

}
