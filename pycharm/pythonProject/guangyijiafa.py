import pandas as pd
from pygam import LinearGAM, s
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt
import numpy as np

# 加载数据
df = pd.read_csv('instead.csv')

# 去除列名中的空格
df.columns = df.columns.str.strip()

# 分离特征和目标变量
X = df[['M1', 'M2', 'M3', 'M4', 'R', 'P', 'E','RP','RE','PE']]
y = df['Y']

# 分割数据集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 构建和训练GAM模型
gam = LinearGAM(s(0) + s(1) + s(2) + s(3) + s(4) + s(5) + s(6)+s(7) + s(8) + s(9))
gam.fit(X_train, y_train)

# 预测
y_pred = gam.predict(X_test)

# 评估
print("MSE:", mean_squared_error(y_test, y_pred))
print("R2:", r2_score(y_test, y_pred))

# 提取模型参数
beta = gam.coef_  # 提取所有系数，包括截距项
intercept = beta[0]
print(f"Intercept: {intercept}")

# 获取每个特征的平滑函数
feature_functions = {}
for i, term in enumerate(gam.terms):
    if term.isintercept:
        continue
    XX = gam.generate_X_grid(term=i)
    pd = gam.partial_dependence(term=i, X=XX)
    feature_functions[X.columns[i]] = (XX[:, i], pd)

# 打印每个特征的平滑函数
for feature, (x, y) in feature_functions.items():
    print(f"Function relationship for {feature}:")
    for xi, yi in zip(x, y):
        print(f"{feature}: {xi}, Effect: {yi}")

# 可视化平滑函数
for feature, (x, y) in feature_functions.items():
    plt.figure()
    plt.plot(x, y)
    plt.xlabel(feature)
    plt.ylabel('Effect on Y')
    plt.title(f'Partial dependence of {feature}')
    plt.show()

# 构建总的关系式
def total_effect(intercept, feature_functions, input_values):
    total = intercept
    for feature, (x, y) in feature_functions.items():
        input_value = input_values[feature]
        # 找到最接近的平滑函数值
        closest_index = np.argmin(np.abs(x - input_value))
        effect = y[closest_index]
        total += effect
    return total

# 示例输入值
input_values = {
    'M1': 10.5,
    'M2': 20.3,
    'M3': 30.7,
    'M4': 40.2,
    'R': 1.0,
    'P': 0.5,
    'E': 2.1
}

# 计算总的效果
total_effect_value = total_effect(intercept, feature_functions, input_values)
print(f"Total effect on Y: {total_effect_value}")
