//
// Created by 김헌우 on 2023/06/24.
//
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
//    pos ++;
//    dat[pos] = x; 코드 축약 가능
    dat[pos++] = x;

}

void pop(){
//    dat[pos] = 0; 이건 필요 없음
    pos --;

}

int top(){
    return dat[pos-1];

}

void test(){
    push(5); push(4); push(3);
    cout << top() << '\n'; // 3
    pop(); pop();
    cout << top() << '\n'; // 5
    push(10); push(12);
    cout << top() << '\n'; // 12
    pop();
    cout << top() << '\n'; // 10
}

int main(void) {
    test();
}
