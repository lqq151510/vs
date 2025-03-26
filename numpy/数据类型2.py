import numpy as np
# 获取int16类型的信息
ii16=np.iinfo(np.int16)
# 打印int16类型的最小值
print(ii16.min)
# 打印int16类型的最大值
print(ii16.max)

# 获取int32类型的信息
ii32=np.iinfo(np.int32)
# 打印int32类型的最小值
print(ii32.min)
# 打印int32类型的最大值
print(ii32.max)
# 获取float16类型的浮点数信息
ff16=np.finfo(np.float16)
# 打印float16类型的最小值
print(ff16.min)
# 打印float16类型的最大值
print(ff16.max)
# 打印float16类型的位数
print(ff16.bits)
# 打印float16类型的最小精度（epsilon）
print(ff16.eps)


# 获取float32类型的浮点数信息
ff32=np.finfo(np.float32)
# 打印float32类型的最小正数
print(ff32.min)
# 打印float32类型的最大正数
print(ff32.max)
# 打印float32类型的位数
print(ff32.bits)
print(ff32.eps)


