//
// Created by 김헌우 on 2023/07/08.
//
#include <bits/stdc++.h>
using namespace std;

int k, input[20], arr[10];

void func(int num, int cur) {
    if (num == 6) {
        for (int i = 0; i < 6; i++) cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = cur; i < k; i++) {
        arr[num] = input[i];
        func(num + 1, i + 1);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (1) {
        cin >> k;
        if (k == 0) break;
        for (int i = 0; i < k; i++) cin >> input[i];
        func(0, 0);
        cout << '\n';
    }
}