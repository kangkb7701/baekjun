import sys


# 같은 depth에서 같은 원소를 안고르면 되는거 아냐?
def dfs(arr, depth, ans, visited):
    arr.sort()

    if depth == m:
        print(*ans)
        return

    last_val = 0  # 새로운 depth로 갈땐 초기화해줘야지
    for i in range(n):
        if visited[i]:
            continue
        if arr[i] == last_val:
            continue
        visited[i] = True
        ans.append(arr[i])
        last_val = arr[i]  # **이거 지역변수 개념 진짜 이거때매 한참 헤맸네;;**
        dfs(arr, depth + 1, ans, visited)
        ans.pop()
        visited[i] = False


input = sys.stdin.readline
n, m = map(int, input().split())
arr = list(map(int, input().split()))
ans = []
visited = [False] * n

dfs(arr, 0, ans, visited)
