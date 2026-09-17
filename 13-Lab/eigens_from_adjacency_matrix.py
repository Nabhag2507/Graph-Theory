import numpy as np

A = np.array([
    [0, 1, 1],
    [1, 0, 1],
    [1, 1, 0]
])

eigenvalues, eigenvectors = np.linalg.eig(A)

print("Eigenvalues:")
print(eigenvalues)

print("\nEigenvectors:")
print(eigenvectors)