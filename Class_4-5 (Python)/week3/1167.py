import sys
from collections import deque

input = sys.stdin.readline

n = int(input())
tree = [[] for _ in range(n + 1)]

for _ in range(n):
    tmp = list(map(int, input().split()))
    u = tmp[0]
    x = 1
    while tmp[x] != -1:
        tree[u].append((tmp[x], tmp[x + 1]))
        x += 2

# 디버깅용
# for i in range(n):
#     print(*tree[i + 1])


# 트리 탐색 두번으로 지름찾기, 첫탐색 : depth가 가장 낮은 지점 찾기, 다음 탐색 :
def bfs(start):
    d = [-1] * (n + 1)  # d[index] :start 부터 index까지의 sum_d
    d[start] = 0
    q = deque([(start, 0)])  # 덱에 튜플 자료형으로 삽입

    farthest = start
    farthest_w = 0

    while q:
        pos, weight = q.popleft()

        # 지름 끝점 찾기
        if weight > farthest_w:
            farthest = pos
            farthest_w = weight

        for next, next_w in tree[pos]:
            if d[next] == -1:
                new_w = weight + next_w
                d[next] = new_w
                q.append((next, new_w))

    return farthest, farthest_w


endpoint, _ = bfs(1)
_, diameter = bfs(endpoint)  # diameter : 지름

print(diameter)
