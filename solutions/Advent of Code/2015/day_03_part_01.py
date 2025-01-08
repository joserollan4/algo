ans = {(0,0)}
x, y = 0, 0
s = str(input())
for e in s:
    if e == '^':
        y += 1
    elif e == 'v':
        y -= 1
    elif e == '<':
        x -= 1
    elif e == '>':
        x += 1
    ans.add((x,y))
print(len(ans))
