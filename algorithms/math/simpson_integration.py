def simpsons(A, B, *args): # integral of f(x)dx from A to B
    N = 100000
    h = (B - A) / N
    ans = f(B,*args) + f(A,*args) # f is some function
    for i in range(1,N):
        x = A + h * i
        if i % 2 == 1:
            ans += (f(x,*args) * 4)
        else:
            s += (f(x,*args) * 2)
    ans *= (h/3)
    return s
