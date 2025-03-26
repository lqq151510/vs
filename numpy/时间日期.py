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

# 导入numpy库
import numpy as np
# 打印变量date_range的值（假设date_range已经被定义）
print(date_range)


# 计算两个日期之间的差值，并打印结果及其数据类型
# np.datetime64用于表示日期时间
a=np.datetime64('2020-01-02')-np.datetime64('2020-01-01')
print(a,a.dtype)  # 输出：1 days, dtype='timedelta64[D]'
# 计算两个具体时间点之间的差值，并打印结果及其数据类型
b=np.datetime64('2020-01-02 20:00:00')-np.datetime64('2020-01-02 10:00:00')
print(b,b.dtype)  # 输出：10 hours, dtype='timedelta64[h]'

# 创建一个表示1年的时间差，并打印结果
a=np.timedelta64(1,'Y')
print(a)  # 输出：1 years
# 将1年的时间差转换为月，并打印结果
b=np.timedelta64(a,'M')
# 导入NumPy库，用于处理数值计算和时间序列
import numpy as np
# 打印变量a的值（假设a在此之前已经被定义）
print(a)
# 打印变量b的值（假设b在此之前已经被定义）
print(b)
# 创建一个时间差对象c，表示1小时
c=np.timedelta64(1,'h')
# 创建一个时间差对象d，基于c（1小时），转换为分钟
d=np.timedelta64(c,'m')
# 打印时间差对象c的值
print(c)
# 打印时间差对象d的值
print(d)
# 创建一个时间差对象a，表示1年
a=np.timedelta64(1,'Y')
# 创建一个时间差对象b，表示6个月
b=np.timedelta64(6,'M')
# 创建一个时间差对象c，表示1周
c=np.timedelta64(1,'W')
# 创建一个时间差对象d，表示1天
d=np.timedelta64(1,'D')
# 创建一个时间差对象e，表示10天
e=np.timedelta64(10,'D')
# 打印时间差对象a的值
print(a)
# 打印时间差对象b的值
print(b)
# 打印时间差对象c的值
print(c)
# 打印时间差对象d的值
print(d)
# 打印时间差对象e的值
print(e)
# 打印时间差对象a和b相加的结果（1年 + 6个月）
print(a+b)
# 打印时间差对象a和b相减的结果（1年 - 6个月）
print(a-b)
# 打印时间差对象a乘以2的结果（1年 * 2）
print(2*a)
# 打印时间差对象a除以b的结果（1年 / 6个月）
print(a/b)
# 打印时间差对象c除以d的结果（1周 / 1天）
print(c/d)
# 打印时间差对象c对e取模的结果（1周 % 10天）
print(c%e)

a=np.busday_offset('2020-07-10',offsets=1,roll='forward')#2020-07-13
'''2020-07-10' 是基准日期。
offsets=1 表示从基准日期开始增加 1 个工作日。
roll='forward' 表示如果计算出的日期不是工作日，则向前滚动到下一个工作日。
因此，a 的值将是 '2020-07-13'，因为 2020 年 7 月 11 日和 12 日是周末，所以需要滚动到下一个工作日'''
print(a)
b=np.busday_offset('2020-07-10',offsets=0,roll='forward')#2020-07-10,2020-07-10' 是基准日期。offsets=0 表示不增加或减少工作日。
print(b)
c=np.busday_offset('2020-07-10',offsets=1,roll='backward')#2020-07-13
print(c)
d=np.busday_offset('2020-07-10',offsets=0,roll='backward')#2020-07-10
print(d)

a=np.is_busday('2020-07-10')#判断是不是工作日，返回布尔值
b=np.is_busday('2020-07-11')
c=np.is_busday('2020-07-12')
print(a,b,c)


# 导入NumPy库，用于处理数值计算和日期时间
import numpy as np
# 定义开始日期为2020年1月1日，使用np.datetime64类型
begindates=np.datetime64('2020-01-01')
# 定义结束日期为2020年12月31日，使用np.datetime64类型
enddates=np.datetime64('2020-12-31')
# 使用np.arange生成从开始日期到结束日期的日期范围数组，步长为1天，数据类型为datetime64[D]
# 这里的a和date_range是同一个变量，date_range没有被使用
a=np.arange(begindates,enddates,dtype='datetime64[D]')
# 使用np.is_busday判断日期数组a中的每个日期是否为工作日（周一到周五），并返回布尔数组
# 使用np.count_nonzero计算布尔数组中True的数量，即工作日的总数
b=np.count_nonzero(np.is_busday(a))
# 打印日期范围数组a
print(a)
# 打印工作日的总数b
print(b)

a=np.is_busday('2020-07-10',weekmask='1111100')#判断是不是工作日，返回布尔值
b=np.is_busday('2020-07-10',weekmask='1111001')
print(a)#True
print(b)#False



# 导入NumPy库，用于处理数值计算和日期时间
import numpy as np
# 定义开始日期为2020年7月10日，使用np.datetime64类型
begindates=np.datetime64('2020-07-10')

# 定义结束日期为2020年7月20日，使用np.datetime64类型
enddates=np.datetime64('2020-07-20')
# 计算从开始日期到结束日期之间的工作日数（不包括结束日期）
# np.busday_count函数用于计算两个日期之间的工作日数
a=np.busday_count(begindates,enddates)
# 计算从结束日期到开始日期之间的工作日数（不包括开始日期）
# 注意这里的结果会是负数，因为结束日期在开始日期之前
b=np.busday_count(enddates,begindates)
# 打印从开始日期到结束日期的工作日数
print(a)
# 打印从结束日期到开始日期的工作日数
print(b)