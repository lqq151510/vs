
import matplotlib.pyplot as plt
import numpy as np
import matplotlib as mpl
print(mpl.get_cachedir())
# 自定义你的数据
x = np.array([400,350,300])         # 横轴数据
y1 = np.array([35.8,50.2,104.1])   # 第一条线的纵轴数据
y2 = np.array([5.4,7.6,10.9])   # 第二条线的纵轴数据

plt.figure(figsize=(10, 6))  
# plt.rcParams['font.family']=['sans-serif']
# plt.rcParams['font.sans-serif']=['SimHei']

# 绘制第一条线（蓝色实线，带圆形标记）
plt.plot(x, y1,
         color='#1f77b4',    # 线条颜色
         linestyle='-',      # 直线样式
         linewidth=2,        # 线宽
         marker='o',         # 数据点标记
         markersize=8,       # 标记大小
         label='折线1')      # 图例标签

# 绘制第二条线（橙色虚线，带方形标记）
plt.plot(x, y2,
         color='#ff7f0e',
         linestyle='--',
         linewidth=2,
         marker='s',
         markersize=8,
         label='折线2')
for xi, yi in zip(x, y1):
    plt.text(xi, yi + 0.01,  # 文字位置（Y轴偏移1.5个单位）
            f'{yi}A',  # 显示带单位的数值
            ha='center',  # 水平居中
            va='bottom',  # 垂直底部对齐
            fontsize=10,
            color='#2D1A60')  # 深紫色文字
for xi, yi in zip(x, y2):
        plt.text(xi, yi + 0.01,  # 文字位置（Y轴偏移1.5个单位）
                f'{yi}A',  # 显示带单位的数值
                ha='center',  # 水平居中
                va='bottom',  # 垂直底部对齐
                fontsize=10,
                color='#2D1A60')  # 深紫色文字

# 添加说明
plt.title('双折线统计图', fontsize=14, fontproperties='SimHei')  # 标题
plt.xlabel('Uak', fontsize=12, fontproperties='SimHei')  # x轴标签
plt.ylabel('I(A)', fontsize=12, fontproperties='SimHei')  # y轴标签

# 设置图例
plt.legend(prop={'family': 'SimHei'})  # 显示图例（需指定中文字体）
line1, = plt.plot(x, y1, label='数据1')
line2, = plt.plot(x, y2, label='数据2')
plt.legend(handles=[line1, line2], labels=['436mm', '546mm'])


# 添加网格线
plt.grid(True, linestyle='--', alpha=0.7)

#自动调整坐标范围
plt.xlim(min(x)-0.5, max(x)+0.5)
plt.ylim(0, max(max(y1), max(y2)) * 1.1)

# 保存图片（可选，保存在代码同目录下）
# plt.savefig('dual_line_plot.png', dpi=300, bbox_inches='tight')

plt.show()  # 显示图表
