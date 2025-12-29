import sys

input = sys.stdin.readline

n = int(input())

lst = list(map(int,input().split()))

max_sum = 2*(10**9) + 1
result=[0,0]

left = 0
right = n - 1

while left < right:
    sum = lst[left]+lst[right]
    abs_sum = abs(sum)

    if abs_sum < max_sum:
        max_sum = abs_sum
        result[0] = lst[left]
        result[1] = lst[right]

        if abs_sum ==0:
            break
    
    if sum < 0: #left 절댓값 > right 절댓값 [-99, .... , 80] -> left값 오른쪽으로 이동
        left += 1
    else: # left 절댓값 < right 절댓값 [-80, ...... , 99] -> right값 왼쪽으로 이동
        right -= 1

print(*result)