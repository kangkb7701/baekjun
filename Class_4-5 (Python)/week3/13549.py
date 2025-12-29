from collections import deque
import sys

input = sys.stdin.readline

limit = 100001
INF = sys.maxsize
# count = 0


def bfs_min_time(n, k) -> int:
    if n >= k:
        return n - k

    deq = deque([])
    deq.append(n)

    time = [INF for _ in range(limit)]
    time[n] = 0  # 0:방문함 -1:방문X
    while deq:
        # global count
        # count += 1
        pos = deq.popleft()  # position 현재 위치
        t = time[pos]
        if pos == k:
            return time[pos]
        next_p = pos * 2
        if next_p < limit and time[next_p] > t:
            time[next_p] = t
            deq.appendleft(next_p)
        for next_p in (pos - 1, pos + 1):
            if (
                0 <= next_p < limit and time[next_p] > t + 1
            ):  # time[next_p] > t + 1 -> T 란 말은 현재 구할 경로가 더 효율적 -> 업데이트 해야됨
                time[next_p] = t + 1
                deq.append(next_p)

    return 0


n, k = map(int, input().split())
print(bfs_min_time(n, k))
# print(count)
