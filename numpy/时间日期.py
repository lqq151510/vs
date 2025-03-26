import numpy as np
# 创建一个日期对象，日期为2020年1月1日
a=np.datetime64('2020-01-01')
# 打印日期对象及其数据类型
print(a,a.dtype)

# 创建一个日期对象，日期为2025年1月1日
a=np.datetime64('2025-01-01')
# 打印日期对象及其数据类型
print(a,a.dtype)

# 创建一个日期时间对象，日期时间为2020年1月1日20时00分00秒
a=np.datetime64('2020-01-01 20:00:00')
# 打印日期时间对象及其数据类型
print(a,a.dtype)

# 创建一个日期时间对象，日期时间为2020年1月1日20时00分
a=np.datetime64('2020-01-01 20:00')
# 打印日期时间对象及其数据类型
print(a,a.dtype)

# 创建一个日期时间对象，日期时间为2020年1月1日20时
a=np.datetime64('2020-01-01 20')
# 打印日期时间对象及其数据类型
print(a,a.dtype)

# 创建一个日期对象，日期为2020年1月，时间单位为天
a=np.datetime64('2020-01','D')
# 打印日期对象及其数据类型
print(a,a.dtype)
# 创建一个日期对象，日期为2020年1月，时间单位为年
a=np.datetime64('2020-01','Y')
# 打印日期对象及其数据类型
print(a,a.dtype)
# 比较两个日期对象，判断是否相等
print(np.datetime64('2020-03')==np.datetime64('2020-03-01'))
print(np.datetime64('2020-03')==np.datetime64('2020-03-02'))

import numpy as np

# 使用完整的日期格式
a = np.array(['2025-03-01', '2025-03-08'], dtype='datetime64')

print(a)

# 定义起始日期和结束日期
start_date = np.datetime64('2023-10-01')
end_date = np.datetime64('2023-10-10')

# 使用arange生成日期范围
date_range = np.arange(start_date, end_date, dtype='datetime64[D]')

print(date_range)


# 定义起始日期和时间
start_date = np.datetime64('2023-10-01T00:00')

# 定义结束日期和时间
end_date = np.datetime64('2023-10-02T00:00')

# 定义时间步长（例如，每小时）
time_step = np.timedelta64(1, 'h')

# 使用 arange 生成日期时间范围
date_range = np.arange(start_date, end_date, time_step)

print(date_range)


a=np.datetime64('2020-01-02')-np.datetime64('2020-01-01')
print(a,a.dtype)
b=np.datetime64('2020-01-02 20:00:00')-np.datetime64('2020-01-02 10:00:00')
print(b,b.dtype)

a=np.timedelta64(1,'Y')
b=np.timedelta64(a,'M')
print(a)
print(b)
c=np.timedelta64(1,'h')
d=np.timedelta64(c,'m')
print(c)
print(d)
a=np.timedelta64(1,'Y')
b=np.timedelta64(6,'M')
c=np.timedelta64(1,'W')
d=np.timedelta64(1,'D')
e=np.timedelta64(10,'D')
print(a)
print(b)
print(c)
print(d)
print(e)
print(a+b)
print(a-b)
print(2*a)
print(a/b)
print(c/d)
print(c%e)
