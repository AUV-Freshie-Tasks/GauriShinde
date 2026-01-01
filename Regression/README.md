## Logistic Regression Library

Example usage:

```python
from Regression import StandardScaler
from Regression import LogisticRegression

A = np.array([[5.0, 10.0, 15.0], 
              [10.0, 20.0, 25.0], 
              [15.0, 30.0, 35.0]])

standard_scaler = StandardScaler()
Y = standard_scaler.fit_transform(A)

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

i = LR.predict(g)

print(f"Accuracy {LR.compute_accuracy(i,h)}")