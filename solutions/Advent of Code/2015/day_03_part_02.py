ans = {(0,0)}
x1, y1 = 0, 0
x2, y2 = 0, 0
s = str(input())
for i in range(len(s)):
    if i % 2 == 0:
        if s[i] == '^':
            y1 += 1
        elif s[i] == 'v':
            y1 -= 1
        elif s[i] == '<':
            x1 -= 1
        elif s[i] == '>':
            x1 += 1
        ans.add((x1,y1))
    else:
        if s[i] == '^':
            y2 += 1
        elif s[i] == 'v':
            y2 -= 1
        elif s[i] == '<':
            x2 -= 1
        elif s[i] == '>':
            x2 += 1
        ans.add((x2,y2))
print(len(ans))
