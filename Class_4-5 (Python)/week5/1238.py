import sys
import heapq

input = sys.stdin.readline
n, m, x = map(int, input().split())
INF = 10**9

# 1. 정방향 그래프 (돌아올 때 X -> i)
g_forward = [[] for _ in range(n + 1)]
# 2. 역방향 그래프 (갈 때 i -> X, 계산은 X -> i_rev)
g_reverse = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b, w = map(int, input().split())

    # 정방향 그래프 저장 (a -> b)
    g_forward[a].append((b, w))
    # 역방향 그래프 저장 (b -> a)
    g_reverse[b].append((a, w))


def dijkstra(start_node, graph):
    d = [INF] * (n + 1)
    d[start_node] = 0
    pq = [(0, start_node)]

    while pq:
        current_w, current_n = heapq.heappop(pq)

        if d[current_n] < current_w:
            continue

        for next_n, next_w in graph[current_n]:
            new_d = current_w + next_w
            if new_d < d[next_n]:
                d[next_n] = new_d
                heapq.heappush(pq, (new_d, next_n))

    return d


# --- 다익스트라 2회 실행 ---

# 1. 돌아오는 시간 (X -> 모든 i): 정방향 그래프 사용
dist_return = dijkstra(x, g_forward)

# 2. 가는 시간 (모든 i -> X): 역방향 그래프에서 X 출발
dist_go = dijkstra(x, g_reverse)

# --- 결과 계산 ---

max_time = 0
for i in range(1, n + 1):
    # 왕복 시간 계산: (i -> X) + (X -> i)
    total_time = dist_go[i] + dist_return[i]

    # 가장 오래 걸린 학생의 시간 갱신
    max_time = max(max_time, total_time)

print(max_time)
