import sys

input = sys.stdin.readline

n,s = map(int,input().split())

sequence = list(map(int,input().split()))

left ,right, sum = 0,0,0

min_length=1e9

while True:
    if sum >= s:
        min_length=min(min_length,right-left)
        sum -= sequence[left]
        left +=1
    elif right == n:
        break
    else:
        sum += sequence[right]
        right+=1

if min_length == 1e9:
    print(0)
else:
    print(min_length)
