import sys
from bisect import bisect_left

input = sys.stdin.readline

n = int(input())
seq = list(map(int, input().split()))

lis = [seq[0]]

for item in seq[1:]:
    # seq의 현재 값이 lis마지막보다 크다면, lis 마지막에 추가
    if item > lis[-1]:
        lis.append(item)
    else:
        # item이상인 가장 왼쪽 idx를 item값으로 덮어씌움
        # bisect는 강강약약, 나와 대등하거나 더 쎈놈이랑만 싸운다.
        idx = bisect_left(lis, item)
        lis[idx] = item

print(len(lis))
