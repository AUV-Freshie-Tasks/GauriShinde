from Regression import StandardScaler
from Regression import LogisticRegressor
import numpy as np

X = np.array(([1.0,2.0,3.0],[4.9,5.56,-6.0],[7.6,8.7,9.00]))
print(type(X))
standard_scaler = StandardScaler()
Y = standard_scaler.fit_transform(X)
print(Y)

A = np.array([[5.0, 10.0, 15.0], 
              [10.0, 20.0, 25.0], 
              [15.0, 30.0, 35.0]])

print(type(A))
standard_scaler = StandardScaler()
Y = standard_scaler.fit_transform(A)
print(Y)
print(isinstance(A, np.ndarray))

B = np.array((1,0,10,0,2))
print(isinstance(B, np.ndarray))

g = np.array([
    [22, 25, 1],
    [25, 30, 2],
    [28, 35, 3],
    [35, 50, 5],
    [40, 65, 6],
    [45, 80, 8]
])

h = np.array([
    [0],
    [0],
    [0],
    [1],
    [1],
    [1],
])

LR = LogisticRegressor(learning_rate = 2,iterations = 500,verbose = True)
LR.fit(g,h)

print(LR.Weights)
print()
print(LR.intercept)
i = LR.predict(g)
print(f"Type of i {type(i)}")
print(i)
print(h)
print(f"Accuracy {LR.compute_accuracy(i,h)}")
