//
// Created by 김헌우 on 2024/02/22.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int T, N, ans;
int weights[9];

void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> weights[i];
    }
}

void init()
{
    ans = 0;
}

void solve()
{
}

int main(void)
{
    // 3
    // 3
    // 1 2 4
    // 3
    // 1 2 3
    // 9
    // 1 2 3 5 6 4 7 8 9
    freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        input();
        init();
        solve();
        cout << "#" << tc << " " << ans << endl;
    }
}
