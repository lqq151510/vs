# 定义一个生成斐波那契数列的函数
def fibonacci():
    # 初始化两个变量a和b，分别表示斐波那契数列的前两个数
    a, b = 0, 1
    # 无限循环，生成斐波那契数列
    while True:
        # 使用yield关键字，返回当前斐波那契数
        yield a
        # 更新a和b的值，a为b，b为a+b
        a, b = b, a + b

# 使用生成器获取斐波那契数列的前10个数
fib_gen = fibonacci()
for _ in range(10):
    print(next(fib_gen))

# def fin():
#     a,b=0,1
#     while True:
#         yield a
#         a,b=b,a+b
   
# f=fin()
# for _ in range(10):
#     print(next(f))
            

