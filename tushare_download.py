# 导入必要的库
import tushare as ts

# 设置 Tushare 的 API Token
ts.set_token('your_api_token')  # 替换为你的 Tushare API Token

# 初始化 Tushare 接口
pro = ts.pro_api()

# 下载股票数据示例
def download_stock_data(stock_code, start_date, end_date):
    """
    下载指定股票的历史数据。
    
    参数:
    - stock_code: 股票代码，例如 '000001.SZ'
    - start_date: 开始日期，格式 'YYYYMMDD'
    - end_date: 结束日期，格式 'YYYYMMDD'
    
    返回:
    - DataFrame: 包含股票历史数据
    """
    try:
        df = pro.daily(ts_code=stock_code, start_date=start_date, end_date=end_date)
        print(f"成功下载 {stock_code} 的数据")
        return df
    except Exception as e:
        print(f"下载数据时出错: {e}")
        return None

# 示例调用
if __name__ == "__main__":
    stock_data = download_stock_data('000001.SZ', '20220101', '20221231')
    if stock_data is not None:
        print(stock_data.head())  # 打印前几行数据
        stock_data.to_csv('000001_SZ.csv', index=False)  # 保存为 CSV 文件
