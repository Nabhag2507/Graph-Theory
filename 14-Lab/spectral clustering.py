import numpy as np

N = 6

edges = [(0, 1), (0, 2), (1, 2), (3, 4), (4, 5), (3, 5)]

# 1. Construct the adjacency matrix
A = np.zeros((N, N))

for u, v in edges:
    A[u][v] = 1
    A[v][u] = 1

print("Adjacency Matrix:")
print(A)

# 2. Compute the degree matrix
D = np.diag(np.sum(A, axis=1))

print("\nDegree Matrix:")
print(D)

# 3. Construct the Laplacian matrix
L = D - A

print("\nLaplacian Matrix:")
print(L)

# 4. Compute eigenvalues and eigenvectors
eigenvalues, eigenvectors = np.linalg.eigh(L)

print("\nEigenvalues:")
print(eigenvalues)

print("\nEigenvectors:")
print(eigenvectors)

# 5. Use the eigenvector corresponding to the
# second smallest eigenvalue (Fiedler vector)
fiedler_vector = eigenvectors[:, 1]

print("\nFiedler Vector:")
print(fiedler_vector)

# Partition vertices based on the sign of the Fiedler vector
cluster1 = [i for i in range(N) if fiedler_vector[i] < 0]
cluster2 = [i for i in range(N) if fiedler_vector[i] >= 0]

print("\nClusters:")
print("Cluster 1:", set(cluster1))
print("Cluster 2:", set(cluster2))
