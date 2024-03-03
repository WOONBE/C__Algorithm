//
// Created by 김헌우 on 2024/03/03.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

struct BC
{
    int y;
    int x;
    int C;
    int P;
};

struct Point
{
    int y;
    int x;
};

int T, M, A;
int a_move[100], b_move[100];
BC bcs[8];

int dy[5] = { 0, -1, 0, 1, 0 };
int dx[5] = { 0, 0, 1, 0, -1 };

void init()
{
    memset(a_move, 0, sizeof(a_move));
    memset(b_move, 0, sizeof(b_move));
    memset(bcs, 0, sizeof(bcs));
}

void input()
{
    cin >> M >> A;
    int dir;
    for (int i = 0; i < M; i++)
    {
        cin >> dir;
        a_move[i] = dir;
    }
    for (int i = 0; i < M; i++)
    {
        cin >> dir;
        b_move[i] = dir;
    }

    int y, x, C, P;
    for (int i = 0; i < A; i++)
    {
        // x y 순서로 입력
        cin >> x >> y >> C >> P;
        // 1부터 시작하므로
        y--;
        x--;
        bcs[i] = { y, x, C, P };
    }
}

int calcDist(Point a, Point b)
{
    return abs(a.y - b.y) + abs(a.x - b.x);
}

int calcMaxEnergy(int a_bcs[8], int b_bcs[8], bool is_possible_a, bool is_possible_b, int a_max, int b_max)
{
    int max_energy = 0;

    if (is_possible_a == 0)
    {
        if (is_possible_b)
            return b_max;
        return 0;
    }

    if (is_possible_b == 0)
    {
        if (is_possible_a)
            return a_max;
        return 0;
    }

    int a_bc_idx = -1;
    int b_bc_idx = -1;
    int temp = 0;

    for (int i = 0; i < A; i++)
    {
        if (a_bcs[i] == 0)
            continue;
        a_bc_idx = i;
        for (int j = 0; j < A; j++)
        {
            if (b_bcs[j] == 0)
                continue;
            b_bc_idx = j;

            if (a_bc_idx == b_bc_idx)
                temp = bcs[a_bc_idx].P;
            else
                temp = bcs[a_bc_idx].P + bcs[b_bc_idx].P;
            max_energy = max(max_energy, temp);
        }
    }
    return max_energy;
}

int chargeBat(Point a, Point b)
{
    int a_bcs[8] = { 0 };
    int b_bcs[8] = { 0 };
    bool is_possible_a = false;
    bool is_possible_b = false;
    int a_max = 0;
    int b_max = 0;
    int a_bc_dist = 0;
    int b_bc_dist = 0;
    BC cur_bc = { 0, 0, 0, 0 };
    for (int i = 0; i < A; i++)
    {
        cur_bc = bcs[i];
        a_bc_dist = calcDist(a, { cur_bc.y, cur_bc.x });
        b_bc_dist = calcDist(b, { cur_bc.y, cur_bc.x });

        if (a_bc_dist <= cur_bc.C)
        {
            a_bcs[i] = 1;
            is_possible_a = true;
            a_max = max(a_max, cur_bc.P);
        }

        if (b_bc_dist <= cur_bc.C)
        {
            b_bcs[i] = 1;
            is_possible_b = true;
            b_max = max(b_max, cur_bc.P);
        }
    }

    int max_energy = calcMaxEnergy(a_bcs, b_bcs, is_possible_a, is_possible_b, a_max, b_max);

    return max_energy;
}

int solve()
{
    int ans = 0;
    // 두 사람은 양쪽 끝에서 시작
    Point a = { 0, 0 };
    Point b = { 9, 9 };
    ans += chargeBat(a, b);

    for (int i = 0; i < M; i++)
    {
        a.y += dy[a_move[i]];
        a.x += dx[a_move[i]];
        b.y += dy[b_move[i]];
        b.x += dx[b_move[i]];
        ans += chargeBat(a, b);
    }

    return ans;
}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    cin >> T;
    int ans = 0;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();
        ans = solve();
        cout << "#" << tc << " " << ans << '\n';
    }

    return 0;
}
