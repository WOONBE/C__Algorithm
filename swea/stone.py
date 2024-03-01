
t = int(input())

for tc in range(1,t+1):
    n, m = list(map(int,input().split()))
    stone_lst = list(map(int,input().split()))

    for _ in range(m):
        i,j,w = map(int,input().split())

        #시작점이 1부터라서 i-1로 0번 인덱스로 잡아줘야함
        #어렵게 생각하기 보단 단순 구현하면서 코드 짜기
        if w == 1:
            for work in range(i-1,i+j-1):
                if work < n: #범위 설정이 필수임, 이부분 헷갈리면 index 오류남
                    if stone_lst[work] == 1: #1이면 0으로 뒤집기
                        stone_lst[work] = 0
                    else: #0이면 1로 뒤집기
                        stone_lst[work] = 1

        elif w == 2:
            for work in range(i-1, i+j-1):
                if work < n: #범위 안일때 i-1번째부터 다 그 색으로 맞춰줌
                    stone_lst[work] = stone_lst[i-1]

        elif w == 3:
            for work in range(1,j+1): # 이부분이 너무 헷갈렸음, j개 돌에 대하여 반복이니 j번하면 ok
                if i-1 -work >=0 and i-1+work <n: #범위 안 지정(이 부분 반대로 했음)
                    if stone_lst[i-1+work] != stone_lst[i-1-work]: #서로 다른값이면
                        pass #건드리지 않음
                    else: #서로 다른 값이면
                        if stone_lst[i-1+work] == 0: #오른쪽 값이 0이면
                            stone_lst[i-1+work] = 1 #1로 뒤집음
                        else:
                            stone_lst[i-1+work] = 0
                        #한번만 끝내는게 아니라 반대쪽도 확인해줘야함
                        if stone_lst[i-1-work] == 0: #왼쪽 값이 0이면
                            stone_lst[i-1-work] = 1
                        else:
                            stone_lst[i-1-work] = 0


    result = ' '.join(map(str,stone_lst)) #map써서 변환해야 값이 똑바로 나옴
    print(f'#{tc} {result}')






