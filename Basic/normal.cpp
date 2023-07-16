//
// Created by 김헌우 on 2023/06/23.
//

#include "normal.h"
#include "iostream"
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,x,t;
    cin >> n >> x;
    while (n--){
        cin >> t;
        if(t<x) cout << t << ' ';
    }
}
