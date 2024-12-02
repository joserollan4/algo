def ok(a):
    a_sort = sorted(a)
    a_revsort = a_sort[::-1]
    if not (a == a_sort or a == a_revsort):
        return False
    for i in range(len(a)-1):
        if abs(a[i]-a[i+1]) not in range(1,4):
            return False
    return True
ans = 0
while True:
    a = [int(x) for x in input().split()]
    if a[0] == 0:
        print(ans)
        exit()
    if ok(a):
        ans += 1
