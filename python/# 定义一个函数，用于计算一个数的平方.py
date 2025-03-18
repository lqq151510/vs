# 定义一个函数，用于计算一个数的平方
def square(x):
    # 返回参数x的平方
    return x*x
s=lambda x: x*x
print(s(3))
y=[lambda x:x*x ,2,3]
print(y[0](y[2]))

mapped=map(lambda x: ord(x)+10, 'FishC')

print(list(mapped))
# 定义一个函数，将输入的字符转换为ASCII码并加10
def mapped(x):
    return ord(x)+10
list(map(mapped, 'FishC'))
print(list(map(lambda x: ord(x)+10, 'FishC')))
j=list(filter(lambda x: x%2, range(10)))
print(j)
# 定义一个函数，判断一个数是否为偶数

