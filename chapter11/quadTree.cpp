//
// Created by 김헌우 on 2023/07/06.
//
#include "bits/stdc++.h"
using namespace std;

int N;
int board[64][64];
int cnt[2]; //0아니면 1(수 리턴하라는 내용은 없어서 그냥 적기만 해놓음)

void solve(int n, int y, int x)
{
    if (n == 1) {
        cout << board[y][x];  //실제로 짤땐 base condition 설정하기 빡셌음
        return;
    }
    bool zero = true, one = true;
    for (int i = y; i < y + n; i++)
        for (int j = x; j < x + n; j++)
            if (board[i][j])
                zero = false;
            else
                one = false;
    if (zero)
        cout << 0;
    else if (one)
        cout << 1;
    else {
        cout << "(";
        solve(n / 2, y, x); //왼쪽 위
        solve(n / 2, y, x + n / 2); //오른쪽 위
        solve(n / 2, y + n / 2, x); //왼쪽 아래
        solve(n / 2, y + n / 2, x + n / 2); //오른쪽 아래
        cout << ")";
    }
    return;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < N; j++)
            board[i][j] = str[j] - '0'; //이 부분이 구상못해서 틀림
    }
    solve(N, 0, 0);
}