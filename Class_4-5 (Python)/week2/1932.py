import sys

input = sys.stdin.readline

n = int(input())
tri = [list(map(int, input().split())) for _ in range(n)]


def dp(tri, i):  # i번째 줄
    tri[i][0] += tri[i - 1][0]
    for x in range(1, i):  # i번째 줄 = 요소가 i+1개 있음
        if i != 1:
            tri[i][x] += max(tri[i - 1][x - 1], tri[i - 1][x])
    tri[i][i] += tri[i - 1][i - 1]


for i in range(1, n):
    dp(tri, i)

print(max(tri[n - 1]))
