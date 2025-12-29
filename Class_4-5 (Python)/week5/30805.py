#
import sys

input = sys.stdin.readline

n = int(input())
list1 = list(map(int, input().split()))
m = int(input())
list2 = list(map(int, input().split()))

common = set(list1) & set(list2)
# print(*common)      #  1,3,7
answer = []
while common:
    max1 = max(common)  # 7
    answer.append(max1)  # 7 추가

    idx1 = list1.index(max1)
    idx2 = list2.index(max1)
    # 7 이후의 수열에서 또 공통부분 찾기 아 미쳤네 이런식으로
    list1 = list1[idx1 + 1 :]
    list2 = list2[idx2 + 1 :]

    common = set(list1) & set(list2)  # 3 나오겟지, 3 넣으면 끝, answer = 7,3

print(len(answer))
print(*answer)
