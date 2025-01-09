def nice(s):
    return True if sum(1 for c in s if c in 'aeiou')>=3 and any(2*c in s for c in 'abcdefghijklmnopqrstuvwxyz') and all(c not in s for c in ['ab', 'cd', 'pq', 'xy']) else False

ans = 0
for i in range(1000):
    s = str(input())
    if nice(s):
        ans += 1
print(ans)
