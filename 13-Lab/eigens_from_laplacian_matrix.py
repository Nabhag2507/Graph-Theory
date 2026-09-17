import numpy as np

L = np.array([
    [ 2, -1, -1],
    [-1,  2, -1],
    [-1, -1,  2]
])

eigenvalues, eigenvectors = np.linalg.eigh(L)

print("Eigenvalues:")
print(eigenvalues)

print("Eigenvectors:")
print(eigenvectors)   