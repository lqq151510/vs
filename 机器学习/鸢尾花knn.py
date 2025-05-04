from sklearn.datasets import load_iris#数据
from sklearn.model_selection import train_test_split, GridSearchCV#划分数据集
from  sklearn.preprocessing import StandardScaler#数据标准化
from sklearn.neighbors import KNeighborsClassifier
#获取数据集
iris=load_iris()  
#数据基本处理
x_train,x_test,y_train,y_test=train_test_split(iris.data,iris.target,test_size=0.2,random_state=22)
scaler = StandardScaler()

# 对特征值进行标准化
x_train= scaler.fit_transform(x_train)
x_test = scaler.transform(x_test)
#机器学习
estimator=KNeighborsClassifier(n_neighbors=9)
#模型调优
prarm_dict={'n_neighbors':[1,3,5]}
estimator=GridSearchCV(estimator, param_grid=prarm_dict, cv=3)
# param_grid: 传入上面定义的参数字典
# cv=3: 使用3折交叉验证
# GridSearchCV会:
# 将数据分成3份(因为cv=3)
# 对每个参数组合(n_neighbors=1/3/5)进行训练和验证
# 共进行3(参数) × 3(折数) = 9次训练+验证
estimator.fit(x_train,y_train)
#模型评估
#1方法1
y_predict=estimator.predict(x_test)
print('预测结果为:\n',y_predict)
print('对比真实值和预测值:\n',y_predict==y_test)
# 方法2
score=estimator.score(x_test,y_test)
print('准确率为:\n',score)
#交叉验证
print('最好结果\n',estimator.best_score_)
print('最好模型\n',estimator.best_estimator_)
print('每次交叉验证准确率结果\n',estimator.cv_results_)