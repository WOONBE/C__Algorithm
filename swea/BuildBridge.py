t = int(input())

for tc in range(1, t + 1):
    island_num, budget = map(int, input().split())
    costs = list(map(int, input().split()))
    costs.sort()  # 비용을 오름차순으로 정렬

    max_bridges = 0  # 건설 가능한 최대 다리 개수
    total_cost = 0  # 건설에 드는 총 비용
    for cost in costs:
        if total_cost + cost <= budget:  # 예산 내에서 다리를 건설할 수 있는 경우
            max_bridges += 1
            total_cost += cost
        else:
            break  # 예산을 초과하면 건설 중단

    print(f'#{tc} {max_bridges} {total_cost}')
