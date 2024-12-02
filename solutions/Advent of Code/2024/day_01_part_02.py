a, b = [], []
while True:
    x, y = map(int,input().split())
    if x == y == 0:
        break
    a.append(x)
    b.append(y)
ans = 0
for i in range(len(a)):
    ans += (a[i]*b.count(a[i]))
print(ans)
