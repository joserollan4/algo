import hashlib
# adapted from https://www.geeksforgeeks.org/md5-hash-python/
def md5(s):
    return hashlib.md5(s.encode()).hexdigest()

ans = 1
while True:
    if md5("iwrupvqb"+str(ans))[:5] == '00000':
        print(ans)
        exit()
    ans += 1
