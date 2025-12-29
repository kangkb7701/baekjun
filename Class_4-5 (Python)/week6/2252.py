import sys

input = sys.stdin.readline

n, m = map(int, input().split())

adj_arr = [[] for _ in range(n + 1)]
degree = [0] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    adj_arr[a].append(b)
    degree[b] += 1

q = []
ans = []
for i in range(1, n + 1):
    if degree[i] == 0:
        q.append(i)

while q:
    first = q.pop()
    ans.append(first)
    for next in adj_arr[first]:
        degree[next] -= 1
        if degree[next] == 0:
            q.append(next)

print(*ans)
