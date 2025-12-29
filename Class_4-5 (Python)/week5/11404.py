import sys

input = sys.stdin.readline
INF = 10**9

n = int(input())
m = int(input())

g = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(n + 1):
    g[i][i] = 0

for _ in range(m):
    n1, n2, w = map(int, input().split())
    g[n1][n2] = min(g[n1][n2], w)

for k in range(1, n + 1):  # 경유지 k
    for i in range(1, n + 1):  # 출발지 i
        for j in range(1, n + 1):  # 도착지 j
            g[i][j] = min(g[i][j], g[i][k] + g[k][j])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if g[i][j] == INF:
            print(0, end=" ")
        else:
            print(g[i][j], end=" ")
    print()
