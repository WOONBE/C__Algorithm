//
// Created by 김헌우 on 2023/06/29.
//1780

#include <bits/stdc++.h>
using namespace std;

int N;
int paper[2200][2200];
int cnt[3]; //-1, 0, 1로 채워진 종이 갯수

//해당 종이 내부에 같은 숫자로만 채워졌는지 확인하는 함수
bool check(int x, int y, int n) { // x,y, n=길이
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (paper[x][y] != paper[i][j])
                return false;
    return true;
}
void solve(int x, int y, int z)
{
    if (check(x, y, z)) {
        cnt[paper[x][y] + 1] += 1; //idx가 0부터 시작하기때문에 이렇게 할당(-1을 0함, 0을 1에 이런식으로 배열에 저장
        return;
    }
    int n = z / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            solve(x + i * n, y + j * n, n);
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> paper[i][j];
    solve(0, 0, N);
    for (int i = 0; i < 3; i++) cout << cnt[i] << "\n";
}

