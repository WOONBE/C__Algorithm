//
// Created by 김헌우 on 2024/05/10.
//

#include <iostream>
using namespace std;


int dp[31];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;


    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 3; i <= N; i++)
    {
        if (i % 2 != 0) dp[i] = 0; //홀수면 0
        else
        {
            for (int j = 2; j <= N; j += 2)
            {
                if (j == 2) dp[i] = dp[i - j] * dp[2];
                else if((i-j) >= 0) dp[i] += dp[i - j] * 2;
            }
        }
    }
    cout <<dp[N];
}
