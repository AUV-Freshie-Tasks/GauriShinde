from logistic_regression import logistic_regression


d = {
    (2,3,4): True,
    (2,3,5): True,
    (5,6,7): False,
    (20,-56,7.0): False,
}

g = {
    (22, 25, 1): False,
    (25, 30, 2): False,
    (28, 35, 3): False,
    (35, 50, 5): True,
    (40, 65, 6): True,
    (45, 80, 8): True
}


a,b = logistic_regression(d,0.004,5000)
print(a)
print(b)
print()
print()

x,y=logistic_regression(g,0.03,2000)
print(x)
print(y)


# print(y.shape)
# print(f)
# print(o)