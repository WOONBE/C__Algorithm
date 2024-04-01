#for 0402 study
from collections import deque

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

def bfs():
    q = deque(virus)
    vis = [[False] * m for _ in range(n)]
    ret = 0
    while q:
        x, y = q.popleft()
        ret += 1
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and board[nx][ny] == 0 and not vis[nx][ny]:
                vis[nx][ny] = True
                q.append((nx, ny))
    return ret

def dfs(k, idx):
    global ans
    if k == 3:
        tmp = bfs()
        ans = max(ans, free_cells - 3 - tmp + len(virus))
        return
    for i in range(idx, len(frees)):
        x, y = frees[i]
        board[x][y] = 1
        dfs(k + 1, i + 1)
        board[x][y] = 0

if __name__ == "__main__":
    n, m = map(int, input().split())
    board = []
    virus = []
    free_cells = 0
    ans = 0
    for i in range(n):
        row = list(map(int, input().split()))
        board.append(row)
        for j in range(m):
            if row[j] == 0:
                free_cells += 1
            elif row[j] == 2:
                virus.append((i, j))
    frees = [(i, j) for i in range(n) for j in range(m) if board[i][j] == 0]
    dfs(0, 0)
    print(ans)
