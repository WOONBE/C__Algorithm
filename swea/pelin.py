t = int(input())

for tc in range(1, t + 1):
    n, m = map(int, input().split())
    arr = [input() for _ in range(n)]

    ans = ''  # 회문을 저장할 변수 초기화
    # 가로 방향에서 회문을 찾음
    for i in range(n):
        for j in range(n - m + 1):  # 가로 방향으로 M 길이의 회문을 찾을 수 있는 범위 설정
            word = arr[i][j:j+m]
            if word == word[::-1]:  # 회문인지 확인
                ans = word

    # 세로 방향에서 회문을 찾음
    for i in range(n - m + 1):  # 세로 방향으로 M 길이의 회문을 찾을 수 있는 범위 설정
        for j in range(n):
            word = ''
            for k in range(m):
                word += arr[i + k][j]
            if word == word[::-1]:  # 회문인지 확인
                ans = word

    print(f'#{tc} {ans}')
