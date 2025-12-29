import sys
from collections import deque

input = sys.stdin.readline

t = int(input())


for _ in range(t):

    n, k = map(int, input().split())
    time = [0] + list(map(int, input().split()))
    adj_arr = [[] for _ in range(n + 1)]
    # 진입차수
    degree = [0] * (n + 1)
    for dir in range(k):
        start, end = map(int, input().split())
        adj_arr[start].append(end)
        degree[end] += 1
    fin = int(input())
    q = deque([])

    dp = [0] * (n + 1)

    for i in range(1, n + 1):
        if degree[i] == 0:
            q.append(i)
            dp[i] = time[i]

    while q:
        build = q.popleft()
        # 현재 지은 건물(build)에 연결돼있는 다음 건물들 = next
        for next in adj_arr[build]:
            dp[next] = max(dp[next], dp[build] + time[next])
            degree[next] -= 1
            if degree[next] == 0:
                q.append(next)

    print(dp[fin])
