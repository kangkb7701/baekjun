import sys
from collections import deque

input = sys.stdin.readline

T = int(input())
for _ in range(T):
    h, w = map(int, input().split())  # 높이 너비
    grid = []
    grid.append(["."] * (w + 2))
    for i in range(h):
        grid.append(["."] + list(input().strip()) + ["."])
    grid.append(["."] * (w + 2))

    # 디버깅
    # for line in grid:
    #     print(*line)

    has_key = [False] * 26
    key_input = input().strip()
    if key_input != "0":
        for k in key_input:
            has_key[ord(k) - ord("a")] = True

    dx = [0, 1, 0, -1]
    dy = [-1, 0, 1, 0]

    q = deque([(0, 0)])
    visited = [[False] * (w + 2) for _ in range(h + 2)]
    visited[0][0] = True

    door_q = [deque() for _ in range(26)]
    ans = 0

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if 0 <= nx < h + 2 and 0 <= ny < w + 2 and visited[nx][ny] != True:
                cell = grid[nx][ny]

                # 1. 벽이라면 무시
                if cell == "*":
                    continue

                visited[nx][ny] = True

                # 빈칸이라면 탐색q에 추가
                if cell == ".":
                    q.append((nx, ny))

                # 2. 문서라면 정답+1
                elif cell == "$":
                    ans += 1
                    q.append((nx, ny))
                # 3. 대문자라면
                elif "A" <= cell <= "Z":
                    idx = ord(cell) - ord("A")
                    if has_key[idx]:
                        q.append((nx, ny))
                    else:
                        door_q[idx].append((nx, ny))

                elif "a" <= cell <= "z":
                    idx = ord(cell) - ord("a")
                    q.append((nx, ny))
                    if not has_key[idx]:
                        has_key[idx] = True
                        while door_q[idx]:
                            q.append(door_q[idx].popleft())

    print(ans)
