from sklearn.datasets import load_breast_cancer
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, recall_score, precision_score, f1_score, roc_auc_score

# 1. 加载数据
data = load_breast_cancer()
X, y = data.data, data.target

# 2. 划分训练集和测试集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 3. 数据标准化（逻辑回归需要特征缩放）
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)

# 4. 训练逻辑回归模型
model = LogisticRegression(max_iter=1000)  # 增加迭代次数确保收敛
model.fit(X_train_scaled, y_train)

# 5. 预测
y_pred = model.predict(X_test_scaled)
y_pred_proba = model.predict_proba(X_test_scaled)[:, 1]  # 正类（Benign）概率

# 6. 计算指标
accuracy = accuracy_score(y_test, y_pred)
recall = recall_score(y_test, y_pred)     # 默认以1（Benign）为正向类
precision = precision_score(y_test, y_pred)
f1 = f1_score(y_test, y_pred)
auc = roc_auc_score(y_test, y_pred_proba)

# 7. 输出结果
print(f"准确率(Accuracy): {accuracy:.4f}")
print(f"召回率(Recall): {recall:.4f}")
print(f"精确率(Precision): {precision:.4f}")
print(f"F1分数(F1): {f1:.4f}")
print(f"AUC值: {auc:.4f}")