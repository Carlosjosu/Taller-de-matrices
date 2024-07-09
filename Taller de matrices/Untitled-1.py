import numpy as np

# Coeficientes de las ecuaciones
A = np.array([[1560, -560], [-560, 1380]])
B = np.array([2, 2])

# Resolver el sistema de ecuaciones lineales
I = np.linalg.solve(A, B)
I1, I2 = I

I1, I2
