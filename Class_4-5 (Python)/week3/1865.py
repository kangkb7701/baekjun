import sys

input = sys.stdin.readline
INF = 1e9


def bellman_ford(n, m, w):
    edges = []
    dist = [INF] * (n + 1)
    dist[1] = 0
    for i in range(m + w):
        s, e, t = map(int, input().split())
        if i >= m:
            t = -t
        else:
            edges.append((e, s, t))
        edges.append((s, e, t))

    for i in range(n):
        for now, next, cost in edges:
            if dist[next] > dist[now] + cost:
                dist[next] = dist[now] + cost
                if i == n - 1:
                    return True
    return False


tc = int(input())

for _ in range(tc):
    n, m, w = map(int, input().split())  # 정점수, 간선수, 음수간선수
    if bellman_ford(n, m, w):
        print("YES")
    else:
        print("NO")
