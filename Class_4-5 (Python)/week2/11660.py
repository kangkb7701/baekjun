import sys

input = sys.stdin.readline

n, m = map(int, input().split())

# arr2d[0][],[][0] 두 라인 0으로 채운 2차원 matrix
arr2d = [[0] * n]
for _ in range(n):
    line = list(map(int, input().split()))
    line.insert(0, 0)
    arr2d.append(line)

dp = [[0] * (n + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        dp[i][j] = arr2d[i][j]
        dp[i][j] = dp[i][j] + dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]

for k in range(m):
    # x1 <= x2, y1 <= y2
    x1, y1, x2, y2 = map(int, input().split())

    sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1]
    print(sum)
