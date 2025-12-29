import sys

sys.setrecursionlimit(10**7)


def dfs(i):
    global ans
    team.append(i)
    visited[i] = True
    selected = select_arr[i]
    if not visited[selected]:
        dfs(selected)
    # 이미 팀에 있는데 또 방문 -> 사이클, 재귀종료
    elif visited[selected] and selected in team:
        ans += len(team[team.index(selected) :])


input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    visited = [False] * (n + 1)
    select_arr = [0] + list(map(int, input().split()))

    ans = 0
    for i in range(1, n + 1):
        team = []
        if not visited[i]:
            dfs(i)

    print(n - ans)
