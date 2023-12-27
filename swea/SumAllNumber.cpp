//
// Created by 김헌우 on 2023/12/27.
//2058

#include <iostream>
using namespace std;
int main() {
    int N;
    cin >> N;
    int a, b, i;
    int sum = 0;
    for(i=0; i<4; i++) {
        a = N % 10;
        N = N / 10;
        sum += a;
    }
    cout << sum << endl;
}
