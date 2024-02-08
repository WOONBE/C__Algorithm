# 상하좌우 회전할 방향 설정
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

# 입력
t = int(input())
for tc in range(1, t+1):
    n = int(input())
    arr = [list(map(int, input().split())) for _ in range(n)]

    max_sum = 0
    for x in range(n):
        for y in range(n):
            bonus_score = 0
            for dir in range(4):
                nx = x + dx[dir]
                ny = y + dy[dir]
                if 0 <= nx < n and 0 <= ny < n:
                    bonus_score += arr[nx][ny]
                else:
                    bonus_score = 0
                    break
            bonus_score -= arr[x][y]
            if bonus_score < 0:
                bonus_score = 0
            elif bonus_score % 2 == 0:
                bonus_score *= 2
            max_sum = max(max_sum, bonus_score)

    print(f'#{tc} {max_sum}')
