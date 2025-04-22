# 导入必要的库
from sklearn.datasets import load_breast_cancer
from sklearn.naive_bayes import GaussianNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, classification_report

# 1. 加载乳腺癌数据集
data = load_breast_cancer()
X = data.data  # 特征数据
y = data.target  # 标签数据 (0:恶性, 1:良性)
feature_names = data.feature_names  # 特征名称
target_names = data.target_names  # 目标类别名称

# 2. 划分训练集和测试集 (70%训练，30%测试)
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# 3. 创建并训练高斯朴素贝叶斯模型
gnb = GaussianNB()
gnb.fit(X_train, y_train)

# 4. 在测试集上进行预测
y_pred = gnb.predict(X_test)

# 5. 评估模型性能
print("模型准确率: {:.2f}%".format(accuracy_score(y_test, y_pred) * 100))
print("\n分类报告:")
print(classification_report(y_test, y_pred, target_names=target_names))

# 6. 对新样本进行预测示例
new_sample = [X_test[0]]  # 使用测试集中的第一个样本作为新样本
prediction = gnb.predict(new_sample)
probabilities = gnb.predict_proba(new_sample)

print("\n新样本预测结果:")
print("预测类别:", target_names[prediction[0]])
print("类别概率:", dict(zip(target_names, probabilities[0])))