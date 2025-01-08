ans = 0
for i in range(1000):
    a = sorted([int(x) for x in input().split('x')])
    ans = ans + 2*(a[0]+a[1]) + a[0]*a[1]*a[2]
print(ans)
