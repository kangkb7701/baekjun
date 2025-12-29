import sys
import heapq

input = sys.stdin.readline

n, m, road = map(int, input().split())  # 노드수, 탐색범위, 간선수
inf = 1e9

item = [0] + list(map(int, input().split()))

adj_arr = [[] for _ in range(n + 1)]

for i in range(road):
    a, b, w = map(int, input().split())
    # 양방향 인접리스트(adjacency list)
    adj_arr[a].append((w, b))
    adj_arr[b].append((w, a))
    # 1 4 5 -> 1~4간선 가중치5 adj_arr[1] = (5,4)


def dijkstra_all_startpoint():
    # 시작노드 설정
    total_item = 0
    for i in range(1, n + 1):
        dist = [inf] * (n + 1)
        dist[i] = 0
        pq = []
        heapq.heappush(pq, (0, i))
        while pq:
            d, now_node = heapq.heappop(pq)

            # 최적화
            if d > dist[now_node]:
                continue
            for next_d, next_node in adj_arr[now_node]:
                total_d = d + next_d

                if total_d < dist[next_node]:
                    dist[next_node] = total_d
                    heapq.heappush(pq, (total_d, next_node))

        # 총 item수 구하기
        current_total_item = 0
        for k in range(1, n + 1):
            if dist[k] <= m:
                current_total_item += item[k]
        total_item = max(total_item, current_total_item)

    return total_item


print(dijkstra_all_startpoint())
