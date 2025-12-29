import sys

input = sys.stdin.readline

n = int(input())
cost = [
    list(map(int, input().split())) for _ in range(n)
]  # n개 집만큼 rgb값 테이블 생성

for i in range(1, n):
    cost[i][0] += min(cost[i - 1][1], cost[i - 1][2])
    cost[i][1] += min(cost[i - 1][0], cost[i - 1][2])
    cost[i][2] += min(cost[i - 1][0], cost[i - 1][1])


print(min(cost[n - 1][0], cost[n - 1][1], cost[n - 1][2]))
