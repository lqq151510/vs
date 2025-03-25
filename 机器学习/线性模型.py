import numpy as np 
from sklearn.model_selection import train_test_split 
from sklearn.linear_model import LinearRegression 
from sklearn.metrics import mean_squared_error, r2_score 

#生成随机数据 
np.random.seed(42) 
X = 2 * np.random.rand(100, 1) 
y = 4 + 3 * X + np.random.randn(100, 1) 

#将 y转换为一维数组
y = y.ravel()

#将数据集分为训练集和测试集 
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42) 

#创建线性回归模型对象 
model = LinearRegression() 

#训练模型 
model.fit(X_train, y_train) 

#对测试集进行预测 
y_pred = model.predict(X_test) 

#计算均方误差和决定系数 
mse = mean_squared_error(y_test, y_pred)
r2 = r2_score(y_test, y_pred)

print(f"均方误差(MSE): {mse}")
print(f"决定系数(R²): {r2}")

print(f"模型的系数: {model.coef_}")
print(f"模型的截距: {model.intercept_}")
