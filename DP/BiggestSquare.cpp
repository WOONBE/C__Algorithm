//
// Created by 김헌우 on 2023/07/15.
//bfs나 dp로 풀이하려 했으나 발상이 안떠올랐음

#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1010][1010], d[1010][1010];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        for(int j = 1; j <= m; ++j)
            board[i][j] = s[j-1] - '0'; // '0' 대신 48도 성립
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(board[i][j]){
                d[i][j] = min({d[i-1][j], d[i][j-1], d[i-1][j-1]}) + 1; //왼쪽, 왼쪽 대각선 위, 위쪽으로 판별/ 최솟값의 +1이 한변의 최대 크기(0부터 시작이므로)
                ans = max(ans, d[i][j]);
            }
        }
    }
    cout << ans * ans;
}


