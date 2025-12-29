import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))

lis = [seq[0]]
# index기록장 하나 더 만들어야해
record = [(0, seq[0])]

for item in seq[1:]:
    if item > lis[-1]:
        lis.append(item)
        record.append((len(lis) - 1, item))
    else:
        idx = bisect_left(lis, item)
        lis[idx] = item
        record.append((idx, item))

# 길이가 4이면 index가 3부터 0까지
idx_count = len(lis) - 1
ans = []
for i in range(len(record) - 1, -1, -1):  # 역순탐색
    if idx_count < 0:
        break

    idx, item = record[i]
    if idx == idx_count:
        ans.append(item)
        idx_count -= 1
print(len(lis))

# 1번
ans.reverse()
print(*ans)

# 2번
# print(*ans[::-1]) 역순출력 바로 가능
