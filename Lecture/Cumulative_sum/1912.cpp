//
// Created by 김헌우 on 2024/09/03.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


int n;
int main(){

    First


    cin >> n;

    vector<int> v(n+1);

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    vector<int> prefix(n+1);

    prefix[0] = v[0];
    int max_num = v[0]; //음수에 대한 처리를 위하여 설정
    for(int i=1; i<n; i++){
        prefix[i] = max(prefix[i-1] + v[i], v[i]);
        max_num = max(prefix[i],max_num);
    }
//
//    int max_num = *max_element(prefix.begin(),prefix.end());

    cout << max_num;
}

