import numpy as np
# a=np.array([1,2,3,4,5])
# print(a,type(a))

# c = np.array([[11, 12, 13, 14, 15],
#               [16, 17, 18, 19, 20],
#               [21, 22, 23, 24, 25],
#               [26, 27, 28, 29, 30],
#               [31, 32, 33, 34, 35]])
# print(c, type(c))

# d=np.array([[(1,2,3),(4,5,6)],[(7,8,9),(10,11,12)]])
# print(d, type(d))

# import numpy as np

# x = [[1,1,1], [1,1,1], [1,1,1]]
# y = np.array(x)
# x[1][2] = 2
# z = np.asarray(x)
# w = np.asarray(x, dtype=np.int32) 



# print(x, type(x))  
# print(y, type(y), y.dtype)
# print(z, type(z), z.dtype)
# print(w, type(w), w.dtype)


# import numpy as np  # 导入numpy库，并简写为np
# def f(x,y):
#     # 定义一个函数f，接受两个参数x和y，返回10*x+y
#     return 10*x+y

# # 使用np.fromfunction生成一个5行4列的二维数组
# # f是生成数组元素的函数，(5,4)是数组的形状，dtype=int指定数组元素的数据类型为整数
# x=np.fromfunction(f,(5,4),dtype=int) 
# # 打印数组x，数组x的类型，以及数组x的元素数据类型
# print(x, type(x), x.dtype)

# # 使用np.fromfunction生成一个3行3列的二维数组
# # lambda i,j:i==j是一个匿名函数，当i等于j时返回1，否则返回0
# x=np.fromfunction(lambda i,j:i==j,(3,3),dtype=int) 
# # 打印数组x，数组x的类型，以及数组x的元素数据类型
# print(x, type(x), x.dtype)

# # 使用np.fromfunction生成一个3行3列的二维数组
# # lambda i,j:i+j是一个匿名函数，返回i和j的和
# x=np.fromfunction(lambda i,j:i+j,(3,3),dtype=int) 
# # 打印数组x，数组x的类型，以及数组x的元素数据类型
# print(x, type(x), x.dtype)

# import numpy as np  # 导入NumPy库，并使用别名np
# # 创建一个包含5个零的一维数组
# x=np.zeros(5)
# print(x)  # 打印数组x
# # 创建一个3行4列的二维数组，所有元素初始化为0
# y=np.zeros((3,4))
# print(y)  # 打印数组y
# # 创建一个二维数组，包含指定的元素
# x=np.array([[1,2,3],[4,5,6]])
# # 创建一个与x形状相同的数组，所有元素初始化为0
# y=np.zeros_like(x)
# print(y)  # 打印数组y

# x=np.ones(5)
# print(x)  # 打印数组x
# x=np.ones([2,3])
# print(x)  # 打印数组x
# x=np.array([[1,2,3],[4,5,6]])
# y=np.ones_like(x)
# print(y)

# x=np.empty(5)
# print(x)  # 打印数组x
# x=np.empty((2,3))
# print(x)  # 打印数组x
# x=np.array([[1,2,3],[4,5,6]])
# y=np.empty_like(x)
# print(y)

# x=np.eye(4)
# print(x)  # 打印数组x
# x=np.eye(2,3)
# print(x)  # 打印数组x
# x=np.identity(4)
# print(x)  # 打印数组x

# x=np.arange(9).reshape((3,3))
# print(x)
# print(np.diag(x))#[0 4 8]
# print(np.diag(x,k=1))#[1 5]
# print(np.diag(x,k=-1))#[3 7]

import numpy as np  # 导入numpy库，并简写为np
# v=[1,3,5,7]  # 定义一个列表v，包含四个整数
# x=np.diag(v)#[1 3 5 7]
# print(x)

# x=np.full((2,4),7)
# print(x)
# x=np.array([[1,2,3],[4,5,6]])
# y=np.full_like(x,7)
# print(y)

x = np.arange(5)
print(x)  # [0 1 2 3 4]

x = np.arange(3, 7, 2)#这里生成了一个从3开始，到7结束（不包括7），步长为2的整数数组。
print(x)  # [3 5]

x = np.linspace(start=0, stop=2, num=9)
print(x)  
# [0.   0.25 0.5  0.75 1.   1.25 1.5  1.75 2.  ]

x = np.logspace(0, 1, 5)#10^0, 10^{0.25}, 10^{0.5}, 10^{0.75}, 10^1
print(np.around(x, 2))#因此，这行代码将对数组 x 中的每个元素四舍五入到小数点后两位，然后打印出这个数组。

x = np.linspace(start=0, stop=1, num=5)
x = [10 ** i for i in x]
print(np.around(x, 2))


personType = np.dtype({
    'names': ['name', 'age', 'weight'],
    'formats': ['U30', 'i8', 'f8']})

a = np.array([('Liming', 24, 63.9), ('Mike', 15, 67.), ('Jan', 34, 45.8)],
             dtype=personType)
print(a, type(a))