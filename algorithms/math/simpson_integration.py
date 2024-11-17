def simpsons(A, B, *args): # integral of f(x)dx from A to B
    N = 100000
    h = (B - A) / N
    s = f(B,*args) + f(A,*args) # f is some function
    for i in range(1,N):
        x = A + h * i
        if i % 2 == 1:
            s += (f(x,a,b) * 4)
        else:
            s += (f(x,a,b) * 2)
    s *= (h/3)
    return s
