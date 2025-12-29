import sys

input = sys.stdin.readline

n = int(input())

A, B, C, D = [], [], [], []

for _ in range(n):
    a, b, c, d = map(int, input().split())
    A.append(a)
    B.append(b)
    C.append(c)
    D.append(d)

ab_mix, cd_mix = {}, {}

for a in A:
    for b in B:
        ab_sum = a + b
        # .get(ab_sum,0) -> ab_sum이라는 key가 있으면 그 값을, 없다면 0으로 세팅하고 가져와라..
        ab_mix[ab_sum] = ab_mix.get(ab_sum, 0) + 1

ans = 0
for c in C:
    for d in D:
        cd_sum = c + d
        if -(cd_sum) in ab_mix:
            ans += ab_mix[-(cd_sum)]

print(ans)
