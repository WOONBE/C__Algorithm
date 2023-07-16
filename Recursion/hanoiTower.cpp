//
// Created by 김헌우 on 2023/06/27.
//

#include <bits/stdc++.h>
using namespace std;

void func(int a, int b, int n){ //a:시작 b:도착
    if(n == 1){ //하나씩 옮길때
        cout << a << ' ' << b << '\n';
        return;
    }
    func(a, 6-a-b, n-1); //6은 1,2,3의 합(탑이 놓일수 있는 위치)
    cout << a << ' ' << b << '\n';
    func(6-a-b, b, n-1);
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cout << (1<<k) - 1 << '\n'; //1을 비트 기준 k칸 밀어라(2의k승)
    func(1, 3, k);
}
