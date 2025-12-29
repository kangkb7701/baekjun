import sys
from collections import deque

input = sys.stdin.readline

n, pd = map(int, input().split())
adj_lst = [[] for _ in range(n + 1)]
degree = [0] * (n + 1)

for _ in range(pd):
    lst = list(map(int, input().split()))
    num = lst[0]
    arr = lst[1:]
    for i in range(num - 1):
        adj_lst[arr[i]].append(arr[i + 1])
        degree[arr[i + 1]] += 1

q = deque([])
ans = []

for i in range(1, n + 1):
    if degree[i] == 0:
        q.append(i)

while q:
    first = q.popleft()
    ans.append(first)
    for next in adj_lst[first]:
        degree[next] -= 1
        if degree[next] == 0:
            q.append(next)

if len(ans) == n:
    print(*ans, end="\n")
else:
    print(0)
