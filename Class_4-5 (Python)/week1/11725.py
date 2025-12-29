import sys
from collections import deque


input = sys.stdin.readline

N = int(input())

adj_list_array = [[] for _ in range(N + 1)]  # 0~N, n+1 개의 []를 가지는 [] 생성
parent = [0] * (N + 1)

for _ in range(N - 1):
    a, b = map(int, input().split())
    adj_list_array[a].append(b)
    adj_list_array[b].append(a)

# 디버깅용
# for i in range(1, N + 1):
#    print(*adj_list_array[i])
# or
#    print(" ".join(map(str, adj_list_array[i])))


def bfs(adj, parent):
    queue = deque(
        [1]
    )  # 이 라이브러리는 큐 안에 들어가는 리스트 자체를 인자값으로 넣어줘야대
    parent[1] = 1
    while queue:
        u = queue.popleft()  # 현재노드
        for i in adj[u]:
            if parent[i] == 0:  # 방문안했다면 = 부모노드를 못찾앗다면,
                parent[i] = u
                queue.append(i)


bfs(adj_list_array, parent)
print("\n".join(map(str, parent[2:])))  # 슬라이싱 : [시작 : 끝 : 간격 ]
