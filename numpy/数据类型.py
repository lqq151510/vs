import numpy as np
# 创建一个数据类型为'b1'的dtype对象，'b1'表示8位有符号字节
a=np.dtype('b1')
# 打印数据类型的类型，对于'b1'，其类型是numpy.int8
print(a.type)
# 打印数据类型的大小，对于'b1'，其大小是1字节
print(a.itemsize)
# 创建一个数据类型为'i1'的dtype对象，'i1'表示8位有符号整数
a=np.dtype('i1')
# 打印数据类型的类型，对于'i1'，其类型是numpy.int8
print(a.type)
# 打印数据类型的大小，对于'i1'，其大小是1字节
print(a.itemsize)
# 创建一个数据类型为'i2'的dtype对象，'i2'表示16位有符号整数
a=np.dtype('i2')
# 打印数据类型的类型，对于'i2'，其类型是numpy.int16
print(a.type)
# 打印数据类型的大小，对于'i2'，其大小是2字节
print(a.itemsize)
# 创建一个数据类型为'i4'的dtype对象，'i4'表示32位有符号整数
a=np.dtype('i4')
# 打印数据类型的类型，对于'i4'，其类型是numpy.int32
print(a.type)
# 打印数据类型的大小，对于'i4'，其大小是4字节
print(a.itemsize)
# 创建一个数据类型为'i8'的dtype对象，'i8'表示64位有符号整数
a=np.dtype('i8')
# 打印数据类型的类型，对于'i8'，其类型是numpy.int64
print(a.type)
# 打印数据类型的大小，对于'i8'，其大小是8字节
print(a.itemsize)


a=np.dtype('u1')# 创建一个数据类型对象a，表示无符号1字节整数（uint8）     
print(a.type)  # 输出数据类型a的类型，即numpy.uint8
print(a.itemsize)  # 输出数据类型a的每个元素的大小（以字节为单位），即1字节
a=np.dtype('u2')  # 创建一个数据类型对象a，表示无符号2字节整数（uint16）
print(a.type)  # 输出数据类型a的类型，即numpy.uint16
print(a.itemsize)  # 输出数据类型a的每个元素的大小（以字节为单位），即2字节
a=np.dtype('u4')  # 创建一个数据类型对象a，表示无符号4字节整数（uint32）
print(a.type)  # 输出数据类型a的类型，即numpy.uint32
print(a.itemsize)  # 输出数据类型a的每个元素的大小（以字节为单位），即4字节
a=np.dtype('u8')  # 创建一个数据类型对象a，表示无符号8字节整数（uint64）
print(a.type)  # 输出数据类型a的类型，即numpy.uint64
print(a.itemsize)  # 输出数据类型a的每个元素的大小（以字节为单位），即8字节



# 创建一个数据类型对象，表示16位浮点数（'f2'）
a=np.dtype('f2')
# 打印数据类型的类型，对于'f2'，它应该是numpy.float16
print(a.type)
# 打印数据类型的大小，对于16位浮点数，它应该是2字节
print(a.itemsize)
# 创建一个数据类型对象，表示32位浮点数（'f4'）
a=np.dtype('f4')
# 打印数据类型的类型，对于'f4'，它应该是numpy.float32
print(a.type)
# 打印数据类型的大小，对于32位浮点数，它应该是4字节
print(a.itemsize)
# 创建一个数据类型对象，表示64位浮点数（'f8'）
a=np.dtype('f8')
# 打印数据类型的类型，对于'f8'，它应该是numpy.float64
print(a.type)
# 打印数据类型的大小，对于64位浮点数，它应该是8字节
print(a.itemsize)

a=np.dtype('S')# 创建一个数据类型对象a，表示字符串类型（'S'）
print(a.type)  # 输出数据类型a的类型，即numpy.str_
print(a.itemsize)  # 0
a=np.dtype('U')# 创建一个数据类型对象a，表示Unicode字符串类型（'U'）
print(a.type)  # 输出数据类型a的类型，即numpy.str_
print(a.itemsize)  #0

a=np.dtype('S3')# 创建一个数据类型对象a，表示字符串类型（'S'）
print(a.type)  # 输出数据类型a的类型，即numpy.str_
print(a.itemsize)  # 3
a=np.dtype('U3')# 创建一个数据类型对象a，表示Unicode字符串类型（'U'）
print(a.type)  # 输出数据类型a的类型，即numpy.str_
print(a.itemsize)  #12