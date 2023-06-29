//
// Created by 김헌우 on 2023/06/29.
//1021
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    deque<int> DQ;
    for (int i = 1; i <= n; i++) DQ.push_back(i);
    int ans = 0;
    while (m--) {
        int t;
        cin >> t;
        int idx = find(DQ.begin(), DQ.end(), t) - DQ.begin(); // idx : t가 있는 위치 , 이 부분이 좀 이해 오래걸렸음
        while (DQ.front() != t) {
            if (idx < DQ.size() - idx) { //left가 더 작으면
                DQ.push_back(DQ.front());
                DQ.pop_front();
            }
            else { //right가 더 작으면
                DQ.push_front(DQ.back());
                DQ.pop_back();
            }
            ans++;
        } //t가 이미 맨앞이면 옮길 필요도 없다
        DQ.pop_front();
    }
    cout << ans;
}
