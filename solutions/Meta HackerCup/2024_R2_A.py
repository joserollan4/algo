def gen(i,j):
    s = ''
    for k in range(i,j):
        s += str(k)
    s += str(j)
    for k in range(j-1,i-1,-1):
        s += str(k)
    return int(s)

fset = frozenset(gen(i,j) for i in range(1,10) for j in range(i,10))

for i in range(1,int(input())+1):
    a, b, m = map(int,input().split())
    ans = 0
    for f in fset:
        if f % m == 0 and a <= f <= b:
            ans += 1
    print("Case #" + str(i) + ":",ans)
