#include <iostream>
#include <string>

using namespace std;

long long arr[4];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0 ;i<4;i++){
        cin >> arr[i];
    }
    string num1 = to_string(arr[0]) + to_string(arr[1]);
    string num2 = to_string(arr[2]) + to_string(arr[3]);
    long long sum_num = stol(num1) + stol(num2);

    cout << sum_num <<"\n";
}
