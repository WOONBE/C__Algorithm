T = int(input())

for t in range(T):
    N, K = list(map(int, input().split()))
    frog = list(map(int, input().split()))
    tot_sum = 0     # 누적합
    last_jump = 0   # 마지막으로 뒤로 뛰었던 칸수
    frog_now = 0    # 현재 위치

    for k in range(K):      # 총 K번 점프하는 동안
        if frog[frog_now] > 0:     # 현재 연잎이 양수면
            frog_now += frog[frog_now] + last_jump     # 현재 칸수 + 마지막 뒷 점프 칸 수 만큼 점프
            if frog_now < 0 or frog_now >= N:       # 연잎 밖으로 뛰었을시 끝
                break
            else:
                last_jump = 0
                tot_sum += frog[frog_now]           # 마지막 뒷점프 초기화하고 누적합 추가
        else:   # 현재 연잎이 음수면
            last_jump = -1 * frog[frog_now]      # 마지막으로 뒤로 점프한 칸 수 기록
            frog_now += frog[frog_now]
            if frog_now < 0 or frog_now >= N:     # 연잎 밖으로 뛰었을시 끝
                break
            else:
                tot_sum += frog[frog_now]       # 누적합 추가

    print(f"#{t+1} {tot_sum}")
