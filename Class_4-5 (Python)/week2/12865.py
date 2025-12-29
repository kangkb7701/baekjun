import sys

input = sys.stdin.readline
# n = 물건개수, k = 전체 w
n, k = map(int, input().split())

wvArr = [[0, 0]]
for _ in range(n):
    w, v = map(int, input().split())
    wvArr.append((w, v))

dpTable = [[0] * (k + 1) for i in range(n + 1)]

for i in range(1, n + 1):
    # 현재 고려할 weight, value
    w = wvArr[i][0]
    v = wvArr[i][1]

    # 현재 무게 1~k
    for j in range(1, k + 1):
        if w <= j:
            dpTable[i][j] = max(
                v + dpTable[i - 1][j - w], dpTable[i - 1][j]
            )  # 1.넣는경우, 2.안넣는경우
        else:
            dpTable[i][j] = dpTable[i - 1][j]

print(dpTable[-1][-1])
