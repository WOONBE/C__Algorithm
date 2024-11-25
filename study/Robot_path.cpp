#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// 방향 벡터: 하, 우, 상, 좌
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int height, width;
int bestDirection, bestY, bestX, startDirection, startY, startX;
char grid[27][27];
bool visited[27][27];
vector<pair<int, int>> candidates; // '#' 위치 저장
string shortestCommands = "-1";


// 탐색 함수
void findPath(int y, int x, int direction, int visitedCount, string commands) {
    if (visitedCount == candidates.size()) {
        if (shortestCommands == "-1" || commands.size() < shortestCommands.size()) {
            shortestCommands = commands;
            bestY = startY;
            bestX = startX;
            bestDirection = startDirection;
        }
        return;
    }

    for (int turn = 0; turn < 4; turn++) {
        int newDirection = (direction + turn) % 4;
        string nextCommand = "A";
        if (turn == 1) nextCommand = "LA";
        else if (turn == 2) nextCommand = "LLA";
        else if (turn == 3) nextCommand = "RA";

        int ny1 = y + dy[newDirection], nx1 = x + dx[newDirection];
        int ny2 = y + 2 * dy[newDirection], nx2 = x + 2 * dx[newDirection];

        if (ny2 < 1 || nx2 < 1 || ny2 > height || nx2 > width) continue;
        if (grid[ny1][nx1] != '#' || grid[ny2][nx2] != '#' || visited[ny1][nx1] || visited[ny2][nx2]) continue;

        visited[ny1][nx1] = visited[ny2][nx2] = true;
        findPath(ny2, nx2, newDirection, visitedCount + 2, commands + nextCommand);
        visited[ny1][nx1] = visited[ny2][nx2] = false;
    }
}

int main() {
    // 입력 처리
    cin >> height >> width;
    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= width; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '#') {
                candidates.push_back({i, j});
            }
        }
    }

    // 시작점 및 방향 설정
    for (auto [y, x] : candidates) {
        startY = y;
        startX = x;
        for (int direction = 0; direction < 4; direction++) {
            startDirection = direction;
            memset(visited, false, sizeof(visited));
            visited[y][x] = true;
            findPath(y, x, direction, 1, "");
        }
    }

    // 최적 시작 방향 출력
    char startChar = 'v';
    if (bestDirection == 1) startChar = '>';
    else if (bestDirection == 2) startChar = '^';
    else if (bestDirection == 3) startChar = '<';

    cout << bestY << " " << bestX << endl;
    cout << startChar << endl;
    cout << shortestCommands << endl;

    return 0;
}
