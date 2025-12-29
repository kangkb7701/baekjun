import sys

input = sys.stdin.readline

n = int(input())
lst = sorted(list(map(int, input().split())))
top = 4000000000
ans = []
for i in range(n - 2):
    fix = lst[i]
    lp = i + 1
    rp = n - 1
    while lp < rp:
        sum = fix + lst[lp] + lst[rp]
        if abs(sum) < abs(top):
            top = sum
            ans = [fix, lst[lp], lst[rp]]
        if sum < 0:
            lp += 1
        elif sum > 0:
            rp -= 1
        else:
            print(*ans)
            sys.exit()

print(*ans)
