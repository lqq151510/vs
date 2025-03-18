# 定义一个函数，用于创建一个计数器
def create_counter():
    # 初始化计数器为0
    count = 0
    
    # 定义一个内部函数，用于计数
    def counter():
        # 使用nonlocal关键字，表示count是外部函数的变量
        nonlocal count
        # 计数器加1
        count += 1
        # 返回计数器的值
        return count
    
    # 返回内部函数
    return counter

# 创建两个独立的计数器
counter1 = create_counter()
counter2 = create_counter()

# 测试计数器
print(counter1())  # 输出: 1
print(counter1())  # 输出: 2
print(counter2())  # 输出: 1
print(counter1())  # 输出: 3