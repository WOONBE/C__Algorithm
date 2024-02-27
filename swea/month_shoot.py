def game(r, score):
    global max_value
    if r == n:
        if max_value < score:  #최댓값보다 score가 커지면 값 갱신
            max_value = score
        return

    for j in range(n):
        if not vis[j] and arr[r][j] >= 0:
            # score += arr[r][j] 여기서 쓸데없이 더해주다가 값이 꼬임(어차피 값 늘려서 밑에서 돌릴꺼임)
            vis[j] = 1
            game(r+1, score+arr[r][j])

            vis[j] = 0

t = int(input())
for tc in range(1, t+1):
    n = int(input())
    arr = [list(map(int,input().split())) for _ in range(n)]
    vis = [0] * (n)
    max_value = -50
    game(0,0)

    print(f'#{tc} {max_value}')

