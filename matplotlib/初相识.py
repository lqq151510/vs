import matplotlib.pyplot as plt
import numpy as np
# fig, ax = plt.subplots()             # 创建一个图像对象和一个坐标轴对象,fig代表整个图形，而ax代表图形中的一个或多个坐标轴。
# ax.plot([1, 2, 3, 4], [1, 4, 2, 3])  # 在坐标轴对象上绘制一条线,第一个列表是x轴的值，第二个列表是y轴的值。因此，这行代码将在坐标轴上绘制一条通过点(1,1)，
# plt.show()                            # 显示图像

x = np.linspace(0, 2, 100)#这行代码的作用是生成一个包含100个元素的数组，这些元素在0到2之间均匀分布。这个数组可以用来作为x轴的数据。

# 导入matplotlib库中的pyplot模块，用于绘制图形
import matplotlib.pyplot as plt
# 创建一个图形和一个子图（ax）的实例
# fig是图形对象，ax是子图对象
fig, ax = plt.subplots()  
# 在子图上绘制第一个图形，x为x轴数据，x为y轴数据，label为图例标签
ax.plot(x, x, label='linear')  
# 在子图上绘制第二个图形，x为x轴数据，x**2为y轴数据，label为图例标签
ax.plot(x, x**2, label='quadratic')  
# 在子图上绘制第三个图形，x为x轴数据，x**3为y轴数据，label为图例标签
ax.plot(x, x**3, label='cubic')  
# 设置x轴的标签为'x label'
ax.set_xlabel('x label') 
# 设置y轴的标签为'y label'
ax.set_ylabel('y label') 
# 设置图形的标题为"Simple Plot"
ax.set_title("Simple Plot")  
# 显示图例，图例内容根据label参数定义
ax.legend() 
# 显示图形
plt.show()