# import numpy as np
#
# # 假设 x 是输入的数据矩阵
# x=[]
# # 第一步：对数据 x 标准化为 X
# X = (x - np.mean(x, axis=0)) / np.std(x, axis=0)
#
# # 第二步：计算样本相关系数矩阵
# R = np.corrcoef(x, rowvar=False)
#
# print('样本相关系数矩阵为：')
# print(R)
#
# # 第三步：计算 R 的特征值和特征向量
# D, V = np.linalg.eig(R)  # D 是特征值构成的向量，V 是特征向量构成的矩阵
#
# # 第四步：计算主成分贡献率和累计贡献率
# lambda = D[::-1]  # 将特征值反转，使其按照从大到小的顺序排列
# contribution_rate = lambda / np.sum(lambda)  # 计算贡献率
# cum_contribution_rate = np.cumsum(lambda) / np.sum(lambda)  # 计算累计贡献率
#
# print('特征值为：')
# print(lambda)
# print('贡献率为：')
# print(contribution_rate)
# print('累计贡献率为：')
# print(cum_contribution_rate)
# print('与特征值对应的特征向量矩阵为：')
# V = np.rot90(V.T)  # 将特征向量矩阵的列进行颠倒
#
# # 计算我们所需要的主成分的值
# m = int(input('请输入需要保存的主成分的个数: '))
# F = np.zeros((x.shape[0], m))  # 初始化保存主成分的矩阵（每一列是一个主成分）
# for i in range(m):
#     ai = V[:, i].reshape(1, -1)  # 将第 i 个特征向量取出，并转置为行向量
#     Ai = np.tile(ai, (x.shape[0], 1))  # 将这个行向量重复 n 次，构成一个 n*p 的矩阵
#     F[:, i] = np.sum(Ai * X, axis=1)  # 对标准化的数据求了权重后要计算每一行的和
#
# print(F)
import numpy as np

def pca(X, k):  # k is the components you want
    # mean of each feature
    n_samples, n_features = X.shape
    mean = np.array([np.mean(X[:, i]) for i in range(n_features)])
    # normalization
    norm_X = X - mean
    # scatter matrix
    scatter_matrix = np.dot(np.transpose(norm_X), norm_X)
    # Calculate the eigenvectors and eigenvalues
    eig_val, eig_vec = np.linalg.eig(scatter_matrix)
    eig_pairs = [(np.abs(eig_val[i]), eig_vec[:, i]) for i in range(n_features)]
    # sort eig_vec based on eig_val from highest to lowest
    eig_pairs.sort(reverse=True)
    # select the top k eig_vec
    feature = np.array([ele[1] for ele in eig_pairs[:k]])
    # get new data
    data = np.dot(norm_X, np.transpose(feature))
    return data


X = np.array([[13.2,8.34,11.15,468.3,13,2.6,0.025,0.025,3.19],
             [12.5,8.66,11.55,1097,8,3.21,0.037,0.026,1.96],
             [13.7,7.63,11.25,742.6,10,4.98,0.084,0.042,4.32],
             [16.3,8.55,14.08,825.7,2.7,5.02,0.04,0.063,8.54],
             [18,7.92,12.71,1196.8,13.5,3.52,0.1,0.051,12.12],
             [11.3,8.35,10.77,1178.5,51.7,3.97,0.025,0.039,1.57],
             [17.4,7.33,7.3,914.2,11.1,3.38,1.053,0.055,7.33],
             [15.4,7.95,11.34,719.1,4.9,2.45,0.132,0.053,5.49],
             [14.7,7.96,11.49,522.4,16.2,2.21,0.026,0.027,2.35],
             [15.4,8.02,17.32,1027,43.5,5.83,0.025,0.072,7.33],
             [15.6,8.63,16.96,1268,1.8,4.09,0.055,0.105,8.16],
              [14.8,9.25,29.52,1206.5,3,4.64,0.039,0.108,7.42],
              [10.2,8.16,10.23,424.5,4.3,2.08,0.025,0.005,1.38],
              [13.6,8.19,10.68,927.8,26.3,4.34,0.464,0.084,6.61],
              [7.3,8.24,12.4,416.3,2.8,2.23,0.025,0.005,1.19],
              [7.4,8.13,11.8,455.9,11.4,1.19,0.025,0.005,4.32],
              [11.3,8.24,12.73,636.5,1,0.9,0.025,0.005,6.39],
              [10,8.12,16.51,661.7,9.7,1.76,0.025,0.005,4.96],
              [11.8,8.5,12.04,546.1,5,0.96,0.025,0.005,11.89]])

print(pca(X, 1))
