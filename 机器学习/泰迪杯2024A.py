import pandas as pd
import numpy as np
import os
import gc
import psutil
from datetime import datetime

# 配置路径
DATA_DIR = "/mnt/g/"
RESULT_DIR = "./results/"
os.makedirs(RESULT_DIR, exist_ok=True)

def log_memory_usage(step):
    print(f"{step}内存使用: {psutil.virtual_memory().percent}%")

# 内存优化函数
def reduce_mem_usage(df):
    for col in df.columns:
        col_type = df[col].dtype
        if col_type != object:
            c_min = df[col].min()
            c_max = df[col].max()
            if str(col_type)[:3] == "int":
                if c_min > np.iinfo(np.int8).min and c_max < np.iinfo(np.int8).max:
                    df[col] = df[col].astype(np.int8)
                elif c_min > np.iinfo(np.int16).min and c_max < np.iinfo(np.int16).max:
                    df[col] = df[col].astype(np.int16)
                elif c_min > np.iinfo(np.int32).min and c_max < np.iinfo(np.int32).max:
                    df[col] = df[col].astype(np.int32)
                else:
                    df[col] = df[col].astype(np.int64)
            else:
                if c_min > np.finfo(np.float16).min and c_max < np.finfo(np.float16).max:
                    df[col] = df[col].astype(np.float16)
                elif c_min > np.finfo(np.float32).min and c_max < np.finfo(np.float32).max:
                    df[col] = df[col].astype(np.float32)
                else:
                    df[col] = df[col].astype(np.float64)
    return df

# 检测日期格式
def detect_date_format(date_str):
    """尝试检测日期字符串的格式"""
    common_formats = [
        '%Y-%m-%d %H:%M:%S',    # 2023-01-01 12:00:00
        '%Y/%m/%d %H:%M:%S',    # 2023/01/01 12:00:00
        '%Y-%m-%d %H:%M',       # 2023-01-01 12:00
        '%Y/%m/%d %H:%M',       # 2023/01/01 12:00
        '%Y%m%d %H:%M:%S',      # 20230101 12:00:00
        '%Y-%m-%d',             # 2023-01-01
        '%Y/%m/%d',             # 2023/01/01
        '%d-%m-%Y %H:%M:%S',    # 01-01-2023 12:00:00
        '%d/%m/%Y %H:%M:%S',    # 01/01/2023 12:00:00
    ]
    
    for fmt in common_formats:
        try:
            datetime.strptime(date_str, fmt)
            return fmt
        except ValueError:
            continue
    return None  # 无法识别格式

# 加载数据（解决编码和日期格式问题）
def load_data(filename):
    try:
        # 尝试常见的中文编码格式
        encodings = ['gbk', 'gb2312', 'utf-8', 'ansi', 'cp936']
        
        for encoding in encodings:
            try:
                # 先读取前几行确定日期格式
                sample = pd.read_csv(
                    os.path.join(DATA_DIR, filename),
                    encoding=encoding,
                    nrows=5
                )
                
                date_col = '时间'  # 假设日期列名为'时间'
                if date_col not in sample.columns:
                    raise ValueError(f"找不到时间列: {date_col}")
                
                # 检测日期格式
                date_format = detect_date_format(str(sample[date_col].iloc[0]))
                if date_format is None:
                    print(f"警告: 无法自动检测日期格式，将使用dateutil解析")
                    date_format = None
                else:
                    print(f"检测到日期格式: {date_format}")
                
                # 分块读取完整数据
                chunks = []
                for chunk in pd.read_csv(
                    os.path.join(DATA_DIR, filename),
                    encoding=encoding,
                    parse_dates=[date_col],
                    date_format=date_format,
                    chunksize=50000
                ):
                    chunks.append(reduce_mem_usage(chunk))
                
                df = pd.concat(chunks)
                
                # 检查必要列
                required_cols = [date_col, '合格产品累计数', '不合格产品累计数']
                if not all(col in df.columns for col in required_cols):
                    missing = [col for col in required_cols if col not in df.columns]
                    raise ValueError(f"缺少必要列: {missing}")
                
                print(f"成功加载 {filename} (编码: {encoding})")
                return df
                
            except UnicodeDecodeError:
                continue
            except Exception as e:
                print(f"尝试编码 {encoding} 时出错: {str(e)}")
                continue
        
        raise ValueError("无法用任何编码格式读取文件")
    
    except Exception as e:
        print(f"加载 {filename} 失败: {str(e)}")
        return None

# 主程序
def main():
    log_memory_usage("初始")
    
    # 加载数据
    print("\n正在加载文件...")
    df_m101 = load_data("M101.csv")
    if df_m101 is not None:
        log_memory_usage("加载M101后")
    
    df_m102 = load_data("M102.csv")
    if df_m102 is not None:
        log_memory_usage("加载M102后")
    
    if df_m101 is None or df_m102 is None:
        print("\n错误: 数据加载失败，请检查文件内容和路径")
        return
    
    # 其他处理逻辑...
    # (保留您原有的任务处理代码)

if __name__ == "__main__":
    main()