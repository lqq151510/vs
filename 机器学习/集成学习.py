from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier, AdaBoostClassifier
from sklearn.metrics import accuracy_score, classification_report

# 加载数据
data = load_iris()
X, y = data.data, data.target

# 数据预处理
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# 定义模型
models = {
    "Logistic Regression": LogisticRegression(max_iter=200),
    "SVM (RBF)": SVC(kernel='rbf', gamma='auto'),
    "Random Forest": RandomForestClassifier(n_estimators=100),
    "AdaBoost": AdaBoostClassifier(n_estimators=50)
}

# 训练与评估
results = {}
for name, model in models.items():
    model.fit(X_train, y_train)
    y_pred = model.predict(X_test)
    acc = accuracy_score(y_test, y_pred)
    report = classification_report(y_test, y_pred, target_names=data.target_names)
    results[name] = {"Accuracy": acc, "Report": report}

# 输出结果
for name, res in results.items():
    print(f"---- {name} ----")
    print(f"Accuracy: {res['Accuracy']:.4f}")
    print(res["Report"])