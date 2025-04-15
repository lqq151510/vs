from sklearn.datasets import fetch_openml
from sklearn.svm import LinearSVC
from sklearn.metrics import accuracy_score, confusion_matrix, ConfusionMatrixDisplay
import time
import warnings
from sklearn.exceptions import ConvergenceWarning
import os
from sklearn.datasets import load_digits  # 用于本地加载数据集的备用方案
import matplotlib.pyplot as plt
from matplotlib import rcParams
from matplotlib.font_manager import FontProperties
import joblib  # 用于保存模型

# 设置支持中文的字体（如未安装可忽略警告）
font_candidates = [
    "/usr/share/fonts/truetype/wqy/wqy-microhei.ttc",
    "/usr/share/fonts/truetype/wqy/wqy-zenhei.ttc",
    "/usr/share/fonts/truetype/arphic/ukai.ttc",
    "/usr/share/fonts/truetype/arphic/uming.ttc"
]
font_prop = None
for font_path in font_candidates:
    if os.path.isfile(font_path):
        font_prop = FontProperties(fname=font_path)
        plt.rcParams['axes.unicode_minus'] = False
        print(f"已设置中文字体: {font_prop.get_name()}")
        break
if font_prop is None:
    print("警告：未找到可用中文字体，可能会导致中文显示问题。")

# 加载MNIST数据集（添加超时机制）
try:
    mnist = fetch_openml('mnist_784', version=1, parser='auto', timeout=30)
    X, y = mnist.data.astype('float32'), mnist.target.astype(int)  # 转换为float32节省内存
    # 划分训练集和测试集
    X_train, X_test, y_train, y_test = X[:60000], X[60000:], y[:60000], y[60000:]
    # 归一化到0-1
    X_train /= 255.0
    X_test /= 255.0
except Exception as e:
    print("无法从OpenML加载MNIST数据集，尝试加载本地数据集。")
    digits = load_digits()
    X, y = digits.data.astype('float32'), digits.target.astype(int)
    # 划分训练集和测试集（使用 80% 数据作为训练集，20% 数据作为测试集）
    split_index = int(0.8 * len(X))
    X_train, X_test, y_train, y_test = X[:split_index], X[split_index:], y[:split_index], y[split_index:]

# 初始化线性SVM模型（适用于大规模数据）
linear_svm = LinearSVC(
    dual=False,         # 样本数 > 特征数时，dual=False更快
    max_iter=5000,      # 增加迭代次数确保收敛
    tol=1e-4,           # 设置更小的收敛容忍度
    random_state=42
)
# 忽略警告
warnings.filterwarnings("ignore", category=FutureWarning)
warnings.filterwarnings("ignore", category=ConvergenceWarning)

# 训练模型并计时
start_time = time.time()
linear_svm.fit(X_train, y_train)
print(f"训练时间：{time.time() - start_time:.2f}秒")

# 预测并评估
y_pred = linear_svm.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print(f"测试集准确率：{accuracy * 100:.2f}%")

# 绘制混淆矩阵
cm = confusion_matrix(y_test, y_pred)
disp = ConfusionMatrixDisplay(confusion_matrix=cm, display_labels=linear_svm.classes_)
disp.plot(cmap=plt.cm.Blues)
plt.title("混淆矩阵", fontproperties=font_prop)
plt.show()

# 保存模型
model_path = "/home/liuyongze/vs/机器学习/linear_svm_model.joblib"
joblib.dump(linear_svm, model_path)
print(f"模型已保存到 {model_path}")