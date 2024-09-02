//
// Created by 김헌우 on 2024/09/02.
//최대 공약수 : 갭을 줄인다는 개념으로 이해(나누고 나서 나머지를 이용하여 계속 연산)


#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;
#define First ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int gcd(int a, int b){
    if(b == 0) return a;
    gcd(b, a % b);
}

int lcd(int a, int b){
    return a * b / gcd(a,b);
}



int main(){

    First
    int a=30;
    int b = 36;

    int c = gcd(a,b);

    cout << c << "\n";






}
