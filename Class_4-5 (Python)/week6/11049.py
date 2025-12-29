import sys

input = sys.stdin.readline

n = int(input())
matrix_arr = []
INF = 10**9

for _ in range(n):
    r, c = map(int, input().split())
    matrix_arr.append([r, c])

dp = [[INF] * n for _ in range(n)]
for i in range(n):
    dp[i][i] = 0

# i,j의 거리로 반복할거야
for dist in range(1, n):  # 1 ~ (n-1)까지
    for i in range(n - dist):  # i = 0 ~ (n-dis)까지
        j = i + dist
        for k in range(i, j):
            cost = (
                dp[i][k]
                + dp[k + 1][j]
                + matrix_arr[i][0] * matrix_arr[k][1] * matrix_arr[j][1]
            )
            dp[i][j] = min(cost, dp[i][j])
print(dp[0][-1])
