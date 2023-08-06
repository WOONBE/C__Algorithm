//
// Created by 김헌우 on 2023/08/06.
//
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    unsigned int t;
    priority_queue<unsigned int, vector<unsigned int>, greater<>> pq; //최소힙으로 선언

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> t;
        if (t)
            pq.push(t);
        else {
            if (pq.empty())
                cout << "0\n";
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}