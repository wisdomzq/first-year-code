# import numpy as np
# import stats as sts
# import pandas as pd
# import matplotlib.pyplot as plt
#
# scores = [3.19,1.96,4.32,8.54,12.12,1.57,7.33,5.49,2.35,7.33,8.16,7.42,1.38,6.61,1.19,4.32,6.39,4.96,11.89]
#
# # 集中趋势的度量
# print('求和：', np.sum(scores))
# print('个数：', len(scores))
# print('平均值:', np.mean(scores))
# print('中位数:', np.median(scores))
#
# print('上四分位数', sts.quantile(scores, p=0.75))
# print('下四分位数', sts.quantile(scores, p=0.25))
# print('最大值:', np.max(scores))
# print('最小值:', np.min(scores))
# print('极差:', np.max(scores) - np.min(scores))
# print('四分位差', sts.quantile(scores, p=0.75) - sts.quantile(scores, p=0.25))
# print('标准差:', np.std(scores))
# print('方差:', np.var(scores))
# print('离散系数:', np.std(scores) / np.mean(scores))
#
#
#
#
# plt.hist(scores, 100, density=True, facecolor='g', alpha=0.9)
# plt.show()
#
# s = pd.Series(scores)
#
# # 偏度
# print(s.skew())
# # 峰度
# print(s.kurt())
#
#
from matplotlib import pyplot as plt
# 新增加的两行
import matplotlib
import numpy as np

# plt.rcParams['font.sans-serif'] = ['SimHei']
# plt.rcParams['axes.unicode_minus'] = False
plt.rcParams['font.sans-serif'] = ['FangSong']  # 用来正常显示中文标签
plt.rcParams['axes.unicode_minus'] = False  # 用来正常显示负号
matplotlib.rc("font", family='FangSong')

a = ["水温", " pH", " 溶解氧", "电导率", " 浊度","高锰酸盐指数", "氨氮", "总磷",]

b = [0.681,0.038,0.477,0.522,0.140,0.309,0.433,0.528]
a_indexes = np.arange(len(a))

plt.bar(range(len(a)), b, color='skyblue')

# 绘制x轴
plt.xticks(a_indexes, a)

plt.xlabel("因素")
plt.ylabel("相关系数")
plt.title("总氮与不同因素的相关性")
plt.legend()
plt.show()
