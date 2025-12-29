import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

maze = [list(map(int, input().strip())) for _ in range(n)]
# dist[x][y][0,1] -> x,y까지의 거리, 0,1: 벽 부쉇는지 여부
dist = [[[0] * 2 for _ in range(m)] for _ in range(n)]

# 오른쪽부터 시계방향 우하좌상
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def bfs(maze) -> int:
    dist[0][0][0] = 1
    q = deque([(0, 0, 0)])

    while q:
        a, b, c = q.popleft()
        if a == n - 1 and b == m - 1:
            return dist[a][b][c]
        for i in range(4):
            nx = a + dx[i]
            ny = b + dy[i]

            # 범위초과면 다음 탐색
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            # 벽이 아니고 방문 안했을때(벽 부쉇는지 여부는 이전 q에서 pop한 값을 따라가야됨)
            if maze[nx][ny] == 0 and dist[nx][ny][c] == 0:
                dist[nx][ny][c] = dist[a][b][c] + 1
                q.append([nx, ny, c])
            # 벽인데 방문 안했을때 1. 이미 벽 부쉈으면 아무것도 안함 2. 벽 안부쉈으면 부수고 가자
            elif maze[nx][ny] == 1 and c == 0 and dist[nx][ny][c] == 0:
                dist[nx][ny][c + 1] = dist[a][b][c] + 1
                q.append([nx, ny, c + 1])
    return -1


print(bfs(maze))
