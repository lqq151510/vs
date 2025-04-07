# -*- coding: utf-8 -*-
"""分类指标计算完整代码（含数据修正与AUC注意事项）"""
from sklearn.metrics import (accuracy_score, precision_score, recall_score,
                             f1_score, confusion_matrix, roc_auc_score)
import numpy as np

# -------------------- 用户原始数据（未修正）--------------------
y_test = [1,1,0,1,0,0,1,0,1,0,1,0,1,0,1,0,1,1,0,0,1,0,1,1,1,0,0,0,1,0]
y_pred_full = [1,0,1,1,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,1,1,1,1,1,1,0,1,0,1,1]

# -------------------- 数据修正 --------------------
# 截取y_pred前32个元素与y_test对齐
y_pred = y_pred_full[:len(y_test)]  # 关键修正步骤

# -------------------- 分类指标计算 --------------------
# 基础指标
accuracy = accuracy_score(y_test, y_pred)
precision = precision_score(y_test, y_pred)
recall = recall_score(y_test, y_pred)
f1 = f1_score(y_test, y_pred)

# 特异度(Specificity)
tn, fp, fn, tp = confusion_matrix(y_test, y_pred).ravel()
specificity = tn / (tn + fp)

# -------------------- 结果输出 --------------------
print(f"[数据修正说明] y_pred长度已从{len(y_pred_full)}修正为{len(y_test)}")
print("=" * 40)
print(f"Accuracy: {accuracy:.4f}")
print(f"Precision: {precision:.4f}")
print(f"Recall/Sensitivity: {recall:.4f}")
print(f"Specificity: {specificity:.4f}")
print(f"F1 Score: {f1:.4f}")

# -------------------- AUC特殊处理 --------------------
# 警告：必须使用概率值，此处为演示虚构概率
np.random.seed(42)
y_proba = np.clip(np.random.randn(32) * 0.3 + np.array(y_pred), 0, 1)  # 模拟概率值
auc = roc_auc_score(y_test, y_proba)
print("\n[!] AUC警告：需用模型输出的概率值（非0/1标签）")
print(f"AUC示例（虚构概率）: {auc:.4f}")

# -------------------- 混淆矩阵验证 --------------------
print("\n混淆矩阵验证:")
print(f"TP={tp}, FP={fp}, FN={fn}, TN={tn}")