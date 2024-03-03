//
// Created by 김헌우 on 2024/03/02.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct Cell
{
    int y;
    int x;

    // 생명력
    int X;
    // 남은 생명력
    int t;
};

// 생명력이 큰 순으로 pq 에 삽입
struct cmp
{
    bool operator()(Cell a, Cell b)
    {
        return a.X < b.X;
    }
};

int T, N, M, K;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int MAP[350][350];
vector<Cell> cells;

void init()
{
    memset(MAP, 0, sizeof(MAP));
    cells.clear();
}

void input()
{
    cin >> N >> M >> K;
    int cellLife;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> cellLife;
            MAP[150 + i][150 + j] = cellLife;
            if (cellLife != 0)
                cells.push_back({ 150 + i, 150 + j, cellLife, cellLife });
        }
    }
}

int bfs()
{
    priority_queue<Cell, vector<Cell>, cmp> activation;
    int dead = 0, ny = 0, nx = 0;
    Cell now;
    while (K > 0)
    {
        K--;
        for (int i = 0; i < cells.size(); i++)
        {
            cells[i].t--;
            // 비활성화 -> 활성화
            if (cells[i].t == -1)
                activation.push(cells[i]);
            // 활성화 -> 죽음
            if (cells[i].t == -cells[i].X)
                dead++;
        }

        while (!activation.empty())
        {
            now = activation.top();
            activation.pop();
            for (int i = 0; i < 4; i++)
            {
                ny = now.y + dy[i];
                nx = now.x + dx[i];
                if (MAP[ny][nx] == 0)
                {
                    MAP[ny][nx] = now.X;
                    cells.push_back({ ny, nx, now.X, now.X });
                }
            }
        }
    }
    return cells.size() - dead;
}

int main()
{
    // freopen("sample_input.txt", "r", stdin);
    int a;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        init();
        input();
        int ret = bfs();
        cout << "#" << tc << " " << ret << "\n";
    }
    return 0;
}