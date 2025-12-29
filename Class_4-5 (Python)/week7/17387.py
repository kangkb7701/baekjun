import sys

input = sys.stdin.readline
MOD = 1000000000

n = int(input())
dp = [[[0] * 1024 for _ in range(10)] for _ in range(n + 1)]

# 길이 1인 경우 초기화
for i in range(1, 10):
    dp[1][i][1 << i] = 1

for i in range(1, n):
    for j in range(10):
        for k in range(2**10):  # 1024

            # 길이가 i, 끝자리 j인 만들 수 있는 계단 총 개수, k = 사용한 숫자집합
            if dp[i][j][k] == 0:
                continue

            if j - 1 >= 0:
                next_k = k | (1 << j - 1)
                dp[i + 1][j - 1][next_k] = (
                    dp[i + 1][j - 1][next_k] + dp[i][j][k]
                ) % MOD

            if j + 1 <= 9:
                next_k = k | (1 << j + 1)
                dp[i + 1][j + 1][next_k] = (
                    dp[i + 1][j + 1][next_k] + dp[i][j][k]
                ) % MOD

ans = 0
for i in range(10):
    ans = (ans + dp[n][i][1023]) % MOD

print(ans)
