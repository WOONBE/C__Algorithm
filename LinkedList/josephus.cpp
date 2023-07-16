#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    queue<int> Q;
    for (int i = 1; i <= n; i++) Q.push(i);
    cout << '<';
    while (!Q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            Q.push(Q.front()); //앞으로 보내고
            Q.pop(); //필요한 수 pop
        }
        cout << Q.front();
        Q.pop();
        if (Q.size()) cout << ", ";
    }
    cout << '>';
}