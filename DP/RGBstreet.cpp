//
// Created by 김헌우 on 2023/07/14.
//앞에 문제들보단 상대적으로 짜기 쉬움(코드는 바킹독 참조)
#include <bits/stdc++.h>
using namespace std;

int d[1005][3];
int r[1005], g[1005], b[1005];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> r[i] >> g[i] >> b[i];
    d[1][0] = r[1];
    d[1][1] = g[1];
    d[1][2] = b[1];
    for(int i = 2; i <= n; i++){
        d[i][0] = min(d[i-1][1],d[i-1][2])+r[i];
        d[i][1] = min(d[i-1][0],d[i-1][2])+g[i];
        d[i][2] = min(d[i-1][0],d[i-1][1])+b[i];
    }
    cout << *min_element(d[n], d[n]+3);
    // cout << min({d[n][0], d[n][1], d[n][2]}); 도 가능
}