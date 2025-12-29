import sys

input = sys.stdin.readline

N = int(input())
W = [list(map(int, input().split())) for _ in range(N)]
INF = 10**9

# 디버깅
# for line in W:
#     print(*line)


# row index = 도시 수, col index = 현재 방문한 도시 비트
# dp[1][0111] <- 현재 도시1에 있고 0,1,2 도시를 방문한 최소비용
dp = [[-1] * ((1 << N) - 1) for _ in range(N)]


def dfs(now, visited):
    # 모두 방문했다면 원점0으로 돌아가는 길이 있는지 확인
    if visited == (1 << N) - 1:
        # 돌아가는 길이 있다면
        if W[now][0] != 0:
            return W[now][0]
        # 돌아가는 길이 없다면, 이 문제에서 이 경우는 없음. 모든 도시 간 간선이 존재하므로
        else:
            return INF

    # 이미 계산한 최소비용이라면 중복계산X
    if dp[now][visited] != -1:
        return dp[now][visited]

    # 다음도시 방문로직(점화식)
    min_cost = INF

    for next in range(N):  # 0,1,2,3
        # 방문안했고 길이 있다면(이 문제는 항상 있긴 하지만)
        if visited & (1 << next) == 0 and W[now][next] != 0:
            cost = dfs(next, visited | 1 << next)
            # 점화식 = 방문할 다음도시가 원점으로 돌아갈 최소비용(cost) + 현재도시에서 다음도시로 가는 비용(W[now][next])
            min_cost = min(min_cost, cost + W[now][next])

    dp[now][visited] = min_cost
    return min_cost


# 어디서 시작하든 상관없음. 도시 0부터 방문, visited = 0001(이진수)이기 때문에 두번째 인자값은 1(10진수)
dfs(0, 1)
print(dp[0][1])
# == print(dfs(0,1))
