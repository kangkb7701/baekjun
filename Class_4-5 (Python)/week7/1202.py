import sys
import heapq

input = sys.stdin.readline

n, k = map(int, input().split())

jewels = []
bags = []

for _ in range(n):
    w, v = map(int, input().split())
    jewels.append([w, v])
jewels.sort()

for _ in range(k):
    bags.append(int(input()))
bags.sort()
# print(*jewels)
# print(*bags)

hq = []  # 우선순위큐 <- 가장 작은 값이 index 0

# index를 밖에 둠으로써 리스트 한번만 훑는다..
j_idx, total_val = 0, 0
for bag_w in bags:
    while j_idx < n and jewels[j_idx][0] <= bag_w:
        heapq.heappush(hq, -jewels[j_idx][1])
        j_idx += 1
    # 해당되는 보석이 없을수도 있다, 만약 있다면 total에 추가
    if hq:
        total_val += -heapq.heappop(hq)

print(total_val)
