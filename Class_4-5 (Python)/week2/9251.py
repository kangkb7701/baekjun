import sys

input = sys.stdin.readline

# split은 공백을 기준으로 리스트를 만드는것
a = input().strip()
b = input().strip()
first = list(a)
second = list(b)

lcs = [[0] * (len(a) + 1) for _ in range(len(b) + 1)]

for i in range(1, len(b) + 1):
    for j in range(1, len(a) + 1):
        if first[j - 1] == second[i - 1]:
            lcs[i][j] += lcs[i - 1][j - 1] + 1
        else:
            lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j])

# for row in lcs:
#     print(*row)

print(lcs[-1][-1])
