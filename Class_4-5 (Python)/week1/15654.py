N, M = map(int, input().split())
numbers = [int(x) for x in input().split()]

numbers.sort()


def bt(ans, depth):
    if depth == M:
        print(" ".join(map(str, ans)))
        return

    for i in range(N):
        if numbers[i] in ans:
            continue
        ans.append(numbers[i])
        bt(ans, depth + 1)
        ans.pop()


anslst = []
bt(anslst, 0)
