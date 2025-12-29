import sys

sys.setrecursionlimit(10**6)


def find(v):
    global parent
    if parent[v] == v:
        return v
    parent[v] = find(parent[v])
    return parent[v]


def union(a, b):
    global parent
    p1 = find(a)
    p2 = find(b)

    if p1 < p2:
        parent[p2] = p1
    else:
        parent[p1] = p2


input = sys.stdin.readline

v, e = map(int, input().split())

edge_list = []

for _ in range(e):
    snode, enode, w = map(int, input().split())
    edge_list.append([w, snode, enode])

edge_list.sort()

parent = [i for i in range(v + 1)]
result = 0


for weight, snode, enode in edge_list:  # 간선 리스트의 요소 순서 변경 (w가 첫 번째)
    if find(snode) != find(enode):  # cycle이 없는 경우
        union(snode, enode)
        result += weight

print(result)
