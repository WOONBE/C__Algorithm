//
// Created by 김헌우 on 2023/06/24.
//
#include "bits/stdc++.h"
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string N;
    cin >> N;
    list<char> L;
    for (auto c : N) L.push_back(c);
    auto cursor = L.end();

    int M;
    cin >> M;


    while (M--) {
        char op;
        cin >> op;
        if (op == 'P') {
            char add;
            cin >> add;
            L.insert(cursor, add);
        }
        else if (op == 'L') { //예외처리
            if (cursor != L.begin()) cursor--;
        }
        else if (op == 'D') {// 예외처리
            if (cursor != L.end()) cursor++;
        }
        else { // 'B'
            if (cursor != L.begin()) {
                cursor--;
                cursor = L.erase(cursor);
            }
        }
    }
    for (auto c : L) cout << c;
}









