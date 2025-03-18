def hanuka(n, a, b, c):
    if n == 1:
        print(a, '-->', c)
    else:
        hanuka(n-1, a, c, b)
        print(a, '-->', c)
        hanuka(n-1, b, a, c)
n=int(input("输入汉诺塔层数"))
hanuka(n, 'A', 'B', 'C')