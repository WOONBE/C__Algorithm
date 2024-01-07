//
// Created by 김헌우 on 2023/12/28.
//1204, 단순히 배열 안에 in(아마 sort 사용해서 빈도수 구하는 방식)

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int T, tc, n;

    cin >> T;

    for (tc = 1; tc <= T; tc++) {
        cin >> n;

        int number[101] = { 0 }, max = 0, index;
        for (int i = 0; i < 1000; i++) {
            int N;
            cin >> N;
            number[N]++;
        }

        for (int i = 100; i > -1; i--) {
            if (max < number[i]) {
                max = number[i];
                index = i;
            }

        }

        cout << '#' << tc << ' ' << index << '\n';

    }
    return 0;
}

