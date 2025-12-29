import sys

input = sys.stdin.readline

n = int(input())
num = list(map(int, input().split()))
m = int(input())

num.insert(0, 0)  # index 0번에 0 삽입

# dpTable 초기값 설정
dp = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    dp[i][i] = 1
for i in range(1, n):
    if num[i] == num[i + 1]:
        dp[i][i + 1] = 1

for d in range(2, n):  # col - row = 2 ~ 6
    for row in range(1, n - d + 1):  #
        col = row + d
        # row, col = 시작index, 도착index
        if num[row] == num[col] and dp[row + 1][col - 1] == 1:
            dp[row][col] = 1

for _ in range(m):
    a, b = map(int, input().split())
    print(dp[a][b])
