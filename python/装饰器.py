
import time
# 定义一个装饰器函数timer，用于计算被装饰函数的运行时间
def timer(func):
    # 打印开始
    print("开始")
    # 记录开始时间
    start=time.time()
    # 调用被装饰的函数
    func()  
    # 记录结束时间
    end=time.time()
    # 打印结束
    print("结束")
    # 打印运行时间，保留两位小数
    print(f"运行时间{(end-start):.2f}秒")
@timer 
# 定义一个函数func
def func():
    # 暂停3秒
    time.sleep(3)
    # 打印"hello world"
    print("hello world")
 