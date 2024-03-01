def game(r, score):
    global result
    if r == n:  #이부분 max_value로 더하기 하려다 실패했음(안해도 어차피 재귀돌면서 알아서 score에 더할거라 )
        result.append(score)
        return

    for j in range(n):
        if not vis[j] and arr[r][j] >= 0:
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

    print(f'#{tc} {max(result)}')

