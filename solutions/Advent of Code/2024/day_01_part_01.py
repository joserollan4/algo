a, b = [], []
while True:
    x, y = map(int,input().split())
    if x == y == 0:
        break
    a.append(x)
    b.append(y)
a.sort()
b.sort()
ans = 0
for i in range(len(a)):
    ans += abs(a[i]-b[i])
print(ans)
