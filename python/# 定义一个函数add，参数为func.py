# 定义一个函数add，参数为func
def add(func):
    # 定义一个内部函数inner
    def inner():
        # 调用func函数，并将返回值赋给x
        x=func()
        # 返回x+1
        return x+1
    # 返回内部函数inner
    return inner
# 定义一个函数cube
def cube(func):
    # 定义一个内部函数inner
    def inner():
        # 调用func函数，并将返回值赋给x
        x=func()
        # 返回x的立方
        return x*x*x
    # 返回内部函数inner
    return inner
def square(func):
    # 定义一个内部函数inner
    def inner():
        # 调用func函数，并将返回值赋给x
        x=func()
        # 返回x的平方
        return x*x
    # 返回内部函数inner
    return inner
@add
@cube
@square
# 定义一个函数func
def func():
    # 返回2
    return 3
print(func())
