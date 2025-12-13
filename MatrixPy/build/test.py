import MatrixBind 

from MatrixBind import MatrixDouble, MatrixFloat, MatrixInt


mat = MatrixDouble([[1.0,3.0],[8.0,4.0]])
mat.display()
print("no. of rows\n")
print(mat.getNumberOfRows())
print("addition\n")
mat2 = MatrixDouble([[4.5,7.8],[1.0,8.2]])
mat2.display()
mat3 = mat.add(mat2)
mat3.display()
print("multiplication\n")
mat.multiply(mat2).display()
print("operator overloading\n")
mat4 = mat +mat2
mat4.display()
print("transpose\n")
mat.transpose().display()
print("inverse\n")
mat.inverse().display()
print("linear equation solver\n")
print(mat.solveLinear([4.0,4.0]))
print("linear equation solver with Cache\n")
print(mat.solveLinearWithCache([4.0,4.0]))
print(mat2.solveLinearWithCache([9,2]))
print(mat.solveLinearWithCache([4.0,4.0]))
print("getter and setter\n")
print(mat.getElement(1,0))
mat.setElement(1,0,6.0)
mat.display()




mat5 = MatrixFloat([[1.0,3.0],[8.0,4.0]])
mat5.display()
print("no. of rows\n")
print(mat5.getNumberOfRows())
print("addition\n")
mat6 = MatrixFloat([[4.5,7.8],[1.0,8.2]])
mat6.display()
mat7 = mat.add(mat2)
mat7.display()
print("multiplication\n")
mat5.multiply(mat6).display()
print("operator overloading\n")
mat8 = mat5 +mat6
mat8.display()
print("transpose\n")
mat5.transpose().display()
print("inverse\n")
mat5.inverse().display()
print("linear equation solver\n")
print(mat5.solveLinear([4.0,4.0]))
print("linear equation solver with Cache\n")
print(mat5.solveLinearWithCache([4.0,4.0]))
print(mat6.solveLinearWithCache([9,2]))
print(mat5.solveLinearWithCache([4.0,4.0]))
print("getter and setter\n")
print(mat5.getElement(1,0))
mat5.setElement(1,0,6.0)
mat5.display()

mat9 = MatrixFloat([[1,3],[8,4]])
mat9.display()
print("no. of rows\n")
print(mat9.getNumberOfRows())
print("addition\n")
mat10 = MatrixFloat([[4,7],[1,8]])
mat10.display()
mat11 = mat.add(mat2)
mat11.display()
print("multiplication\n")
mat9.multiply(mat10).display()
print("operator overloading\n")
mat12 = mat9 +mat10
mat12.display()
print("transpose\n")
mat9.transpose().display()





