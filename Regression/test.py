from Regression import StandardScaler
from Regression import LogisticRegressor
from Regression import LinearRegressor
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

Log_R = LogisticRegressor(learning_rate = 2,iterations = 500,verbose = True)
Log_R.fit(g,h)

print(Log_R.Weights)
print()
print(Log_R.intercept)
i = Log_R.predict(g)
print(f"Type of i {type(i)}")
print(i)
print(h)
print(f"Accuracy {Log_R.compute_accuracy(i,h)}")

Z = np.array([
             [1, 2],
             [2, 1],
             [3, 4],
             [4, 3]])

y = np.array([
             [8],
             [7],
             [18],
             [17]])

Lin_R = LinearRegressor(learning_rate = 0.1,iterations = 500,verbose = True)
Lin_R.fit(Z,y)

j = Lin_R.predict(Z)

print(Lin_R.Weights)
print(Lin_R.intercept)

print(f"Accuracy {Lin_R.compute_accuracy(j,y)}")

