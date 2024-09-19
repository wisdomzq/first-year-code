import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error, r2_score
from sklearn.ensemble import BaggingRegressor
from sklearn.tree import DecisionTreeRegressor
import matplotlib.pyplot as plt

# 加载数据
df = pd.read_csv('data_with_decimals.csv')

# 去除列名中的空格
df.columns = df.columns.str.strip()

# 分离特征和目标变量
X = df[['M1', 'M2', 'M3', 'M4', 'R', 'P', 'E']]
y = df['Y']

# 分割数据集
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# 构建基模型
base_model = DecisionTreeRegressor()

# 构建 Bagging 模型
bagging_model = BaggingRegressor(base_model, n_estimators=50, random_state=42)

# 训练模型
bagging_model.fit(X_train, y_train)

# 预测
y_pred_train = bagging_model.predict(X_train)
y_pred_test = bagging_model.predict(X_test)

# 评估
train_mse = mean_squared_error(y_train, y_pred_train)
test_mse = mean_squared_error(y_test, y_pred_test)
train_r2 = r2_score(y_train, y_pred_train)
test_r2 = r2_score(y_test, y_pred_test)

print(f"Train MSE: {train_mse}")
print(f"Test MSE: {test_mse}")
print(f"Train R2: {train_r2}")
print(f"Test R2: {test_r2}")

# 可视化实际值与预测值的对比
plt.figure(figsize=(10, 5))
plt.scatter(y_test, y_pred_test, edgecolors=(0, 0, 0))
plt.plot([y_test.min(), y_test.max()], [y_test.min(), y_test.max()], 'k--', lw=2)
plt.xlabel('Actual')
plt.ylabel('Predicted')
plt.title('Actual vs Predicted')
plt.show()
