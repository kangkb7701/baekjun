import sys

input = sys.stdin.readline

r, c, t = map(int, input().split())

g = [list(map(int, input().split())) for _ in range(r)]
pos = []

for i in range(r):
    if g[i][0] == -1:
        pos.append(i)

# 1초동안 생기는 일

for _ in range(t):
    tmp_g = [[0] * c for _ in range(r)]
    # 1. 확산
    for i in range(r):
        for j in range(c):
            # r행 c열
            cnt = 0
            if g[i][j] > 0:
                diffusion = g[i][j] // 5
                if i - 1 >= 0 and g[i - 1][j] != -1:
                    tmp_g[i - 1][j] += diffusion
                    cnt += 1
                if j + 1 < c:
                    tmp_g[i][j + 1] += diffusion
                    cnt += 1
                if i + 1 < r and g[i + 1][j] != -1:
                    tmp_g[i + 1][j] += diffusion
                    cnt += 1
                if j - 1 >= 0 and g[i][j - 1] != -1:
                    tmp_g[i][j - 1] += diffusion
                    cnt += 1
                tmp_g[i][j] += g[i][j] - (diffusion * cnt)
    # tmp_g g에 적용
    for i in range(r):
        for j in range(c):
            if tmp_g[i][j] != 0:
                g[i][j] = tmp_g[i][j]

    # 2. 공기청정기
    # 위쪽
    row = pos[0]
    # row -1부터 위로 역순
    for i in range(row - 1, -1, -1):  # 아래방향
        if i + 1 == row:
            g[i][0] = 0
        else:
            g[i + 1][0] = g[i][0]
    for i in range(c):
        if i == 0:
            g[i + 1][0] = g[0][i]
        else:
            g[0][i - 1] = g[0][i]
    for i in range(row):
        if i == 0:
            g[i][c - 2] = g[i][c - 1]
        else:
            g[i - 1][c - 1] = g[i][c - 1]
    for i in range(c - 1, 0, -1):
        if i == c - 1:
            g[row - 1][i] = g[row][i]
        else:
            g[row][i + 1] = g[row][i]

    # 아래쪽
    row = pos[1]
