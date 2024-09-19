import numpy as np
import matplotlib.pyplot as plt
from scipy.linalg import svd

# 读取图像并转换为灰度图
image = plt.imread('test.jpg')
gray_image = np.mean(image, axis=2)  # 将图像转换为灰度图

# 计算SVD
U, S, Vt = svd(gray_image, full_matrices=False)

# 保留前k个奇异值
k_values = [5, 20, 50, 100]

# 创建子图
fig, axs = plt.subplots(1, len(k_values) + 1, figsize=(20, 5))

# 显示原始图像
axs[0].imshow(gray_image, cmap='gray')
axs[0].set_title('Original Image')
axs[0].axis('off')

# 显示压缩后的图像
for i, k in enumerate(k_values):
    # 截断奇异值
    S_k = np.diag(S[:k])
    U_k = U[:, :k]
    Vt_k = Vt[:k, :]

    # 重构压缩后的图像
    compressed_image = np.dot(U_k, np.dot(S_k, Vt_k))

    # 显示压缩后的图像
    axs[i + 1].imshow(compressed_image, cmap='gray')
    axs[i + 1].set_title(f'k = {k}')
    axs[i + 1].axis('off')

# 调整布局
plt.tight_layout()
plt.show()