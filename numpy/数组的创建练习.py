import numpy as np
import datetime
# print(0*np.nan)#nan
# print(np.nan == np.nan)#false
# print(np.inf > np.nan)#false
# print(np.nan - np.nan)#nan
# print(0.3==3*0.1)#false

# dt64=np.datetime64('2020-01-01 22:01:01')
# dt=dt64.astype(datetime.datetime)#astype是NumPy数组的方法，用于转换数组的数据类型。
# print(dt,type(dt))#一个NumPy的datetime64类型对象转换为Python标准库中的datetime对象，并打印出转换后的结果及其类型

# dates=np.arange('2020-02-01','2020-02-10',2,np.datetime64)
# # print(dates)

# out=[]
# for date,d in zip(dates,np.diff(dates)):#这段代码使用zip函数遍历dates数组和日期差值np.diff(dates)。
#     out.extend(np.arange(date,date+d))
# fillin=np.array(out)#首先将out列表转换为NumPy数组fillin
# output=np.hstack([fillin,dates[-1]])#然后使用np.hstack函数将fillin数组和dates数组的最后一个日期水平堆叠起来，形成最终的输出数组output。
# print(output)

# import numpy as np

# yesterday = np.datetime64('today', 'D') - np.timedelta64(1, 'D')#np.timedelta64(1, 'D') 创建一个表示时间间隔的对象，这里表示1天。
# today = np.datetime64('today', 'D')  # 直接使用今天的日期
# tomorrow = np.datetime64('today', 'D') + np.timedelta64(1, 'D')

# print("yesterday is " + str(yesterday))#将昨天的日期转换为字符串并打印出来。
# print("today is " + str(today))
# print("tomorrow is " + str(tomorrow))


# arr=np.arange(10)#创建从0到9的一维数字数组
# print(arr)

# arr=np.full((3,4),True,dtype=bool)#创建一个3行4列的布尔数组，所有元素都是True
# print(arr)创建一个元素全为True的 3×3 数组

# Z=np.zeros(10)#创建一个长度为10并且除了第五个值为1的空向量
# Z[4]=1
# print(Z)

# Z = np.arange(10,50)
# print(Z)#创建一个值域范围从10到49的向量

#创建一个 3x3x3的随机数组
# Z = np.random.random((3,3,3))
# print(Z)

# #创建一个二维数组，其中边界值为1，其余值为0
# Z = np.ones((10,10))
# Z[1:-1,1:-1] = 0#1:-1是Python中的切片操作，表示从索引1开始到倒数第一个索引（不包括）。
# print(Z)
#创建长度为10的numpy数组，从5开始，在连续的数字之间的步长为3。
# start = 5
# step = 3
# length = 10
# a = np.arange(start, start + step * length, step)
# print(a)  # [ 5  8 11 14 17 20 23 26 29 32 35 38 41 44 47 50 53 56 59 62 65 68 71 74 77 80 83 86 89 92 95 98]