

# def func(i):
#     if i>0:
#            print("hello")
#            i-=1
#            func(i)     
# func(10)          


# 定义一个函数fattier，参数为n
# def fattier(n):
#       # 初始化result为n
#         result=n
#       # 循环从1到n-1
#         for i in range(1,n):
#            # result乘以i
#            result*=i
#            # 返回result
#         return result
# i=fattier(5)      
# print(i)


# 定义一个函数fattier，参数为n
def fattier(n):
     # 如果n等于1，返回1
     if n==1:
        return 1
     # 否则，返回n减去fattier(n-1)
     else:
        return n*fattier(n-1)
i=fattier(5)     
print(i)

def fib(n):
    if n==1 or n==2:
        return 1
    else:
        return fib(n-1)+fib(n-2)
print(fib(12))  

def fib(n):
    a,b,c=1,1,1
    while n>2:
        c=a+b
        a=b
        b=c
        n-=1
    return c
print(fib(12))