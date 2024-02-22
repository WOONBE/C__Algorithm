//
// Created by 김헌우 on 2024/02/22.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int T, N, totalSum, ans;
int weights[9];
int visited[9];

int exps[9] = { 1, 2, 4, 8, 16, 32, 64, 128, 256 };
int factorial[9] = { 0, 1, 2, 6, 24, 120, 720, 5040, 40320 };

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
    totalSum = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++)
    {
        totalSum += weights[i];
    }
}

void func(int cnt, int leftSum, int rightSum)
{
    if (cnt == N)
    {
        ans++;
        return;
    }

    // 현재까지의 왼쪽무게가 전체 무게의 절반을 넘었을 때
    // 오른쪽에 다 몰아줘도, 왼쪽을 넘을 수 없다! => 조건 만족
    if (leftSum >= totalSum - leftSum)
    {
        // 남은 갯수(N - cnt)
        // 남은 갯수의 경우의 수를 구하기 위해, 배열을 미리 써둠
        // 그걸 지금까지의 답에 합산
        ans = ans + exps[N - cnt] * factorial[N - cnt];
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 1)
            continue;
        visited[i] = 1;
        // 무조건 왼쪽부터 시작한다.
        func(cnt + 1, leftSum + weights[i], rightSum);

        // 조건을 만족시킨다면, 같은 무게추에서, func 이 두 개 실행되는것처럼 보이지만,
        // 사실, 재귀가 연속되면 (원복이 잘된다고 가정했을 때)
        // "또는" 의 관계다.
        // 왜냐, 아래 구문이 생략된 것이기 때문.
        // visited[i] = 0;
        // visited[i] = 1;
        if (leftSum >= rightSum + weights[i])
            func(cnt + 1, leftSum, rightSum + weights[i]);

        visited[i] = 0;
    }
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
    // freopen("sample_input.txt", "r", stdin);
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        input();
        init();
        func(0, 0, 0);
        cout << "#" << tc << " " << ans << endl;
    }
}
