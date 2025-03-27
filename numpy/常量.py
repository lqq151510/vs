import numpy as np
print(np.nan==np.nan) #False
print(np.nan!=np.nan) #True

x=np.array([1,1,8,np.nan,10])
print(x)
y=np.isnan(x) #判断是否为nan
print(y)
z=np.count_nonzero(y)#这里使用了numpy的count_nonzero方法来统计布尔数组中True值的数量
print(z)
