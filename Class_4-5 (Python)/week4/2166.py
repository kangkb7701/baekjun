from sys import stdin

input = stdin.readline

n = int(input())
x = [0]*(n+1)
y=[0]*(n+1)
for i in range(n):
    x[i],y[i] = map(int,input().split())

x[n] = x[0]
y[n] = y[0]

a=0
b=0

for i in range(n):
    a += x[i]*y[i+1]
    b += x[i+1]*y[i]

sum = 0.5*abs(a-b)
print(sum)