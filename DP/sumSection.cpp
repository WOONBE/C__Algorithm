//
// Created by 김헌우 on 2024/02/08.
//

#include <iostream>
#include <algorithm>


using namespace std;
int sum_arr[100004];
int num_arr[100004];
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    sum_arr[0] = 0;

    for(int i=1; i<=n; i++){
        cin >> num_arr[i];
        sum_arr[i] = sum_arr[i-1] + num_arr[i];
    }

    while(m--){
        int i,j;
        cin >> i >> j;
        cout << sum_arr[j] - sum_arr[i-1] << "\n";
    }

}
