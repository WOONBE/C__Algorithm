//
// Created by 김헌우 on 2023/12/27.
//1936
#include<iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin >> a >> b;
    if ((a == 1 && b == 2) || (a == 1 && b == 3) || (a == 3 && b == 2)){
        cout << 'A';
    }
    else if ((a == 2 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 1)){
        cout << 'B';
    }

}
