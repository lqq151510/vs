# # 导入必要库
# from sklearn import datasets
# from sklearn.model_selection import train_test_split
# from sklearn.preprocessing import StandardScaler
# from sklearn.svm import SVC
# from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

# # 加载数据集
# iris = datasets.load_iris()
# X = iris.data  # 特征矩阵（萼片/花瓣的测量数据）
# y = iris.target  # 目标变量（三种鸢尾花类别）

# # 数据预处理
# X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=52)
# scaler = StandardScaler()
# X_train = scaler.fit_transform(X_train)
# X_test = scaler.transform(X_test)

# # 创建SVM分类器（使用默认RBF核）
# svm = SVC(kernel='rbf', random_state=42)

# # 模型训练
# svm.fit(X_train, y_train)

# # 预测测试集
# y_pred = svm.predict(X_test)

# # 性能评估
# print(f"准确率: {accuracy_score(y_test, y_pred):.2f}")
# print("\n混淆矩阵:")
# print(confusion_matrix(y_test, y_pred))
# print("\n分类报告:")
# print(classification_report(y_test, y_pred, target_names=iris.target_names))
# 网格搜索示例（需结合图片中的参数影响规律）
# 补全完整代码（包含数据准备、调优、诊断三部分）
from sklearn import datasets
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.preprocessing import StandardScaler
from sklearn.svm import SVC
from sklearn.metrics import accuracy_score
import matplotlib.pyplot as plt
import numpy as np

# 数据准备（模拟图中二维特征）
iris = datasets.load_iris()
X = iris.data[:, :2]  # 取前两个特征模拟图中的X1,X2
y = iris.target

# 数据预处理（与图中坐标范围匹配）
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# 网格搜索参数设置（严格对齐图片参数范围）
param_grid = {
    'C': [0.001, 0.01, 0.1, 1, 10, 100, 1000],  # 包含图片中的C=0.001和C=1000极端值
    'gamma': [0.001, 0.01, 0.1, 1, 5, 10]       # 包含图片中的γ=0.1和γ=5典型值
}

# 执行网格搜索（增加refit=True用于后续可视化）
grid = GridSearchCV(SVC(kernel='rbf', random_state=42), 
                   param_grid, 
                   cv=5,
                   n_jobs=-1,
                   return_train_score=True)
grid.fit(X_train_scaled, y_train)

# 最优参数输出（补充测试集验证）
best_svc = grid.best_estimator_
y_pred = best_svc.predict(X_test_scaled)
print(f"最优参数：{grid.best_params_}")
print(f"测试集准确率：{accuracy_score(y_test, y_pred):.2f}")

# 可视化诊断（模拟图中四宫格效果）
plt.figure(figsize=(12, 8))

# 生成网格点坐标（匹配图中坐标范围）
x_min, x_max = X_train_scaled[:, 0].min() - 1, X_train_scaled[:, 0].max() + 1
y_min, y_max = X_train_scaled[:, 1].min() - 1, X_train_scaled[:, 1].max() + 1
xx, yy = np.meshgrid(np.linspace(x_min, x_max, 100),
                     np.linspace(y_min, y_max, 100))

# 绘制四种典型参数组合的决策边界（对应图片案例）
param_combinations = [
    {'C': 0.001, 'gamma': 0.1},  # 左上：欠拟合
    {'C': 1000, 'gamma': 0.1},   # 右上：适度拟合
    {'C': 0.001, 'gamma': 5},    # 左下：欠拟合
    {'C': 1000, 'gamma': 5}      # 右下：过拟合
]

for i, params in enumerate(param_combinations, 1):
    plt.subplot(2, 2, i)
    # 修复参数解包语法错误
    svc = SVC(kernel='rbf', **params).fit(X_train_scaled, y_train)
    Z = svc.predict(np.c_[xx.ravel(), yy.ravel()]).reshape(xx.shape)
    
    # 绘制决策边界（模拟图中紫色区域）
    plt.contourf(xx, yy, Z, alpha=0.3, cmap='cool')
    
    # 绘制支持向量（蓝色方块）和数据点（绿色三角）
    plt.scatter(X_train_scaled[:, 0], X_train_scaled[:, 1], 
                c=y_train, cmap='viridis', edgecolors='k', 
                marker='^', s=50, label='Data Points')
    plt.scatter(svc.support_vectors_[:, 0], svc.support_vectors_[:, 1],
                facecolors='none', edgecolors='blue', 
                s=100, linewidths=2, label='Support Vectors')
    
    plt.title(f"γ={params['gamma']}, C={params['C']}\nSVs:{len(svc.support_vectors_)}")
    plt.xlabel('X1 (标准化后)')
    plt.ylabel('X2 (标准化后)')

plt.tight_layout()
plt.show()