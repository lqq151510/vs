#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import numpy as np
import pandas as pd
import pandas_ta as ta
import yfinance as yf
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, TensorDataset
from sklearn.preprocessing import MinMaxScaler
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestRegressor, GradientBoostingRegressor, VotingRegressor
from xgboost import XGBRegressor
from sklearn.svm import SVR
from sklearn.metrics import mean_squared_error
import matplotlib.pyplot as plt

# 1. 数据获取与预处理函数
def get_stock_data(tickers, start_date, end_date):
    data = yf.download(tickers, start=start_date, end=end_date, group_by='ticker')
    if len(tickers) > 1:
        dfs = []
        for ticker in tickers:
            df = data[ticker].copy().reset_index()
            df['Ticker'] = ticker
            dfs.append(df)
        return pd.concat(dfs, ignore_index=True)
    else:
        data['Ticker'] = tickers[0]
        return data.reset_index()

def preprocess_data(df):
    if 'Date' not in df.columns:
        if isinstance(df.index, pd.DatetimeIndex):
            df = df.reset_index().rename(columns={'index': 'Date'})
        else:
            raise KeyError("输入数据缺少 'Date' 列，且无法自动修复。请检查数据格式！")

    if 'Ticker' in df.columns:
        df = df.drop_duplicates(subset=['Date', 'Ticker'], keep='first')
    else:
        df = df.drop_duplicates(subset=['Date'], keep='first')

    if not np.issubdtype(df['Date'].dtype, np.datetime64):
        df['Date'] = pd.to_datetime(df['Date'])

    # 技术指标计算
    df.ta.rsi(length=14, append=True)
    df.ta.macd(append=True)
    df.ta.stoch(append=True)
    df.ta.ema(length=12, append=True)
    df.ta.sma(length=20, append=True)
    df.ta.bbands(append=True)

    # 滞后特征
    for lag in [1, 3, 5, 10]:
        df[f'Close_lag_{lag}'] = df['Close'].shift(lag)
        df[f'Volume_lag_{lag}'] = df['Volume'].shift(lag)

    df['Target'] = df['Close'].pct_change(5).shift(-5)
    return df.dropna().reset_index(drop=True)

# 2. 神经网络模型
class StockNN(nn.Module):
    def __init__(self, input_size):
        super().__init__()
        self.net = nn.Sequential(
            nn.Linear(input_size, 256),
            nn.BatchNorm1d(256),
            nn.LeakyReLU(0.01),
            nn.Dropout(0.3),
            nn.Linear(256, 128),
            nn.BatchNorm1d(128),
            nn.LeakyReLU(0.01),
            nn.Dropout(0.2),
            nn.Linear(128, 64),
            nn.BatchNorm1d(64),
            nn.LeakyReLU(0.01),
            nn.Linear(64, 1)
        )

    def forward(self, x):
        return self.net(x)

# 3. 传统机器学习模型训练
def train_ml_models(X_train, y_train):
    models = [
        ('rf', RandomForestRegressor(n_estimators=200, random_state=42)),
        ('xgb', XGBRegressor(n_estimators=200, learning_rate=0.1, random_state=42, verbosity=0)),
        ('gbr', GradientBoostingRegressor(n_estimators=200, learning_rate=0.1, random_state=42)),
        ('svr', SVR(kernel='rbf', C=1.0, epsilon=0.1))
    ]

    results = {}
    for name, model in models:
        model.fit(X_train, y_train)
        results[name] = model
    return results

# 4. 模型集成
def build_ensemble(ml_results, nn_model, X_train, y_train):
    class NNWrapper:
        def __init__(self, model):
            self.model = model

        def predict(self, X):
            self.model.eval()
            with torch.no_grad():
                return self.model(torch.FloatTensor(X)).numpy().flatten()

    estimators = [(name, res) for name, res in ml_results.items()]
    estimators.append(('nn', NNWrapper(nn_model)))

    ensemble = VotingRegressor(estimators=estimators, weights=[1, 1, 1, 2])
    ensemble.fit(X_train, y_train)
    return ensemble

# 5. 主流程（修正日期列处理）
def train_and_predict(train_tickers, test_data, start_date, end_date):
    # 训练数据准备
    raw_train = get_stock_data(train_tickers, start_date, end_date)
    processed_train = preprocess_data(raw_train)

    feature_cols = [col for col in processed_train.columns if col not in ['Date', 'Ticker', 'Target']]
    X_train = processed_train[feature_cols].values
    y_train = processed_train['Target'].values

    scaler = MinMaxScaler()
    X_train_scaled = scaler.fit_transform(X_train)

    # 训练神经网络
    nn_model = StockNN(X_train_scaled.shape[1])
    optimizer = optim.Adam(nn_model.parameters(), lr=0.001)
    criterion = nn.MSELoss()

    train_loader = DataLoader(
        TensorDataset(torch.FloatTensor(X_train_scaled), torch.FloatTensor(y_train)),
        batch_size=64, shuffle=True
    )

    for epoch in range(100):
        nn_model.train()
        for inputs, targets in train_loader:
            optimizer.zero_grad()
            outputs = nn_model(inputs)
            loss = criterion(outputs, targets)
            loss.backward()
            optimizer.step()

    # 训练传统模型
    ml_results = train_ml_models(X_train_scaled, y_train)

    # 构建集成模型
    ensemble = build_ensemble(ml_results, nn_model, X_train_scaled, y_train)

    # 测试数据预处理（加强日期列处理）
    test_data = test_data.rename(columns={
        '股票代码': 'Ticker',
        '日期': 'Date',
        '开盘': 'Open',
        '收盘': 'Close',
        '最高': 'High',
        '最低': 'Low',
        '成交量': 'Volume',
        '涨跌幅': 'Pct_Change'
    })

    # 确保Date列存在并转换格式
    if 'Date' not in test_data.columns:
        test_data['Date'] = pd.to_datetime(test_data.index)
    else:
        test_data['Date'] = pd.to_datetime(test_data['Date'])

    # 确保特征列一致
    for col in feature_cols:
        if col not in test_data.columns:
            test_data[col] = np.nan

    processed_test = preprocess_data(test_data)
    X_test = processed_test[feature_cols].values
    X_test_scaled = scaler.transform(X_test)

    # 进行预测
    test_preds = ensemble.predict(X_test_scaled)
    processed_test['Predicted_Return'] = test_preds

    return {
        'predictions': processed_test,
        'ensemble': ensemble,
        'scaler': scaler
    }

# 6. 可视化函数
def visualize_results(predictions):
    plt.figure(figsize=(15, 8))
    plt.plot(predictions['Date'], predictions['Close'], label='Close Price', alpha=0.7)
    plt.plot(predictions['Date'], predictions['Close'] * (1 + predictions['Predicted_Return']), 
             label='Predicted 5-day Return', linestyle='--', alpha=0.7)
    plt.legend()
    plt.grid(True)
    plt.show()

# 使用示例
if __name__ == "__main__":
    test_data = pd.read_csv('test.csv')
    result = train_and_predict(
        train_tickers=['AAPL', 'MSFT'],
        test_data=test_data,
        start_date='2020-01-01',
        end_date='2023-01-01'
    )
    visualize_results(result['predictions'])

