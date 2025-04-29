from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, recall_score, precision_score, f1_score, roc_auc_score
from sklearn.preprocessing import label_binarize
import numpy as np

# 1. 加载数据
data = load_iris()
X, y = data.data, data.target
# 定义一个变量 class_names，用于存储数据集中的目标名称
class_names = data.target_names 


# 2. 划分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)#42 1.00

# 3. 数据标准化
scaler = StandardScaler()#这里创建了一个StandardScaler对象，名为scaler。StandardScaler用于标准化特征，使得每个特征具有单位方差和零均值。
X_train_scaled = scaler.fit_transform(X_train)#fit_transform方法是StandardScaler的一个方法，它首先计算训练数据X_train的均值和标准差（即拟合数据），然后使用这些参数将数据转换为标准正态分布（即标准化数据）。
#X_train_scaled是标准化后的训练数据。
X_test_scaled = scaler.transform(X_test)#transform方法使用在训练数据上学习到的均值和标准差来转换测试数据X_test。
#X_test_scaled是标准化后的测试数据。

# 4. 训练KNN模型
model = KNeighborsClassifier()#这是scikit-learn库中的一个分类器，用于实现K近邻算法。
model.fit(X_train_scaled, y_train)#y_train是训练数据集的标签，即每个训练样本的类别。

# 5. 预测
y_pred = model.predict(X_test_scaled)#方法用于对测试数据进行预测，返回的是每个测试样本的预测分类标签。
y_pred_proba = model.predict_proba(X_test_scaled) #方法用于对测试数据进行预测，返回的是每个测试样本属于各个分类的概率。
#y_pred_proba 是一个二维数组，每一行对应一个测试样本，每一列对应一个分类，数组中的值表示该样本属于对应分类的概率。

# 6. 计算指标（多分类需指定average策略）
accuracy = accuracy_score(y_test, y_pred)
recall = recall_score(y_test, y_pred, average='macro')
precision = precision_score(y_test, y_pred, average='macro')
f1 = f1_score(y_test, y_pred, average='macro')

# 7. 计算AUC（OvR策略）
y_test_bin = label_binarize(y_test, classes=[0, 1, 2])
n_classes = y_test_bin.shape[1]
auc = roc_auc_score(y_test_bin, y_pred_proba, average='macro', multi_class='ovr')

# 8. 输出结果
print(f"准确率(Accuracy): {accuracy:.4f}")
print(f"召回率(Recall): {recall:.4f}")
print(f"精确率(Precision): {precision:.4f}")
print(f"F1分数(F1): {f1:.4f}")
print(f"AUC值: {auc:.4f}")