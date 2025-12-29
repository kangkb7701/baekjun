import sys
import math
import heapq

input = sys.stdin.readline
INF = math.inf


def dijkstra(V, startn, g):
    d = [INF] * (V + 1)
    d[startn] = 0
    # 우선순위큐(파이썬에서는 import heapq로 리스트가 우선순위큐 형태로 바뀜)
    pq = [(0, startn)]

    while pq:
        currentw, currentn = heapq.heappop(pq)

        # 현재까지 발견된 최단 거리 < 지금 큐에서 꺼낸 경로의 거리 : 탐색필요없음
        if d[currentn] < currentw:
            continue

        # current node에 연결된 node와 weight
        for nextw, nextn in g[currentn]:
            new_d = currentw + nextw  # nextn 까지 가는 거리
            if new_d < d[nextn]:
                d[nextn] = new_d
                heapq.heappush(pq, (new_d, nextn))

    return d


V, E = map(int, input().split())
startn = int(input())

g = [[] for _ in range(V + 1)]
for _ in range(E):
    u, v, w = map(int, input().split())
    g[u].append((w, v))  #  가중치, 도착지

d = dijkstra(V, startn, g)

for i in range(1, V + 1):
    if d[i] == INF:
        print("INF")
    else:
        print(d[i])  # print하면 줄바꿈 그냥해줌
