dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]

cdx = [0, -1, 0, 1]
cdy = [1, 0, -1, 0]

def dust_spread(room, r, c):
    dummy = [[0] * c for _ in range(r)]
    dummy2 = [[0] * c for _ in range(r)]

    for i in range(r):
        for j in range(c):
            if room[i][j] <= 0:
                continue
            dummy2[i][j] = room[i][j]
            for dir in range(4):
                x = i + dx[dir]
                y = j + dy[dir]
                if x < 0 or y < 0 or x >= r or y >= c:
                    continue
                if room[x][y] == -1:
                    continue
                dummy[x][y] += room[i][j] // 5
                dummy2[i][j] -= room[i][j] // 5

    for i in range(r):
        for j in range(c):
            if room[i][j] == -1:
                continue
            room[i][j] = dummy[i][j] + dummy2[i][j]

def clockwise_wind(i, j, dir, prev_dust, room, r, c):
    if room[i][j] == -1:
        return

    move_dust = room[i][j]
    room[i][j] = prev_dust
    x = i + dx[dir]
    y = j + dy[dir]
    if x < 0 or y < 0 or x >= r or y >= c:
        dir += 1
        x = i + dx[dir]
        y = j + dy[dir]
        clockwise_wind(x, y, dir, move_dust, room, r, c)
    else:
        clockwise_wind(x, y, dir, move_dust, room, r, c)

def counter_clockwise_wind(i, j, dir, prev_dust, room, r, c):
    if room[i][j] == -1:
        return

    move_dust = room[i][j]
    room[i][j] = prev_dust
    x = i + cdx[dir]
    y = j + cdy[dir]
    if x < 0 or y < 0 or x >= r or y >= c:
        dir += 1
        x = i + cdx[dir]
        y = j + cdy[dir]
        counter_clockwise_wind(x, y, dir, move_dust, room, r, c)
    else:
        counter_clockwise_wind(x, y, dir, move_dust, room, r, c)

def air_cleaner(room, r, c, machine_bottom):
    x2 = machine_bottom
    x1 = x2 - 1

    counter_clockwise_wind(x1, 1, 0, 0, room, r, c)
    clockwise_wind(x2, 1, 0, 0, room, r, c)

def dust_sum(room, r, c):
    total_sum = 0
    for i in range(r):
        for j in range(c):
            if room[i][j] == -1:
                continue
            total_sum += room[i][j]
    return total_sum

def main():
    r, c, t = map(int, input().split())
    room = [list(map(int, input().split())) for _ in range(r)]
    machine_bottom = 0

    for i in range(r):
        for j in range(c):
            if room[i][j] == -1:
                machine_bottom = i

    for _ in range(t):
        dust_spread(room, r, c)
        air_cleaner(room, r, c, machine_bottom)

    print(dust_sum(room, r, c))

if __name__ == "__main__":
    main()
