//
// Created by 김헌우 on 2023/07/05.
//앞선 numberOfPaper와 매우 유사
#include "bits/stdc++.h"
using namespace std;
int N;
int paper[128][128];
int cnt[2]; //0, 1로 채워진 종이 갯수

//해당 종이 내부에 같은 숫자로만 채워졌는지 확인하는 함수
bool check(int x, int y, int n) { // x,y, n=길이
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (paper[x][y] != paper[i][j])
                return false;
    return true;
}
void solve(int x, int y, int n)
{
    if (check(x, y, n)) {
        cnt[paper[x][y]]++ ;
        return;
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            solve(x + i * n/2, y + j * n/2, n/2);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    solve(0, 0, N);
    for (int i = 0; i < 2; i++) cout << cnt[i] << "\n";
}
