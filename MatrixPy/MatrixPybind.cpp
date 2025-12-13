#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "Matrix.h"
#include <vector>
namespace py = pybind11;
using namespace std;

PYBIND11_MODULE(MatrixBind, m) {
	
     py::class_<Matrix<double>>(m, "MatrixDouble")
        .def(py::init<int,int>())
        .def(py::init<vector<vector<double>>>())
        .def("display", &Matrix<double>::display)
	.def("getElement", &Matrix<double>::getElement)
	.def("setElement", &Matrix<double>::setElement) 
	.def("getNumberOfRows", &Matrix<double>::getNumberOfRows)
	.def("getNumberOfColumns", &Matrix<double>::getNumberOfColumns)
	.def("add", &Matrix<double>::add)
	.def("subtract", &Matrix<double>::subtract)
	.def("multiply", &Matrix<double>::multiply)
	.def("__add__", &Matrix<double>::add)
        .def("__sub__", &Matrix<double>::subtract)	
        .def("__mul__", &Matrix<double>::multiply)
        .def("inverse", &Matrix<double>::inverse)
	.def("transpose", &Matrix<double>::transpose)
	.def("solveLinear", &Matrix<double>::solveLinear)
	.def("solveLinearWithCache", &Matrix<double>::solveLinearWithCache)
        .def("linearRegression", &Matrix<double>::linearRegression);
	

     py::class_<Matrix<float>>(m, "MatrixFloat")
        .def(py::init<int,int>())
        .def(py::init<vector<vector<float>>>())
        .def("display", &Matrix<float>::display)
	.def("getElement", &Matrix<float>::getElement)
	.def("setElement", &Matrix<float>::setElement) 
	.def("getNumberOfRows", &Matrix<float>::getNumberOfRows)
	.def("getNumberOfColumns", &Matrix<float>::getNumberOfColumns)
	.def("add", &Matrix<float>::add)
	.def("subtract", &Matrix<float>::subtract)
	.def("multiply", &Matrix<float>::multiply)
	.def("__add__", &Matrix<float>::add)
        .def("__sub__", &Matrix<float>::subtract)	
        .def("__mul__", &Matrix<float>::multiply)
        .def("inverse", &Matrix<float>::inverse)
	.def("transpose", &Matrix<float>::transpose)
	.def("solveLinear", &Matrix<float>::solveLinear)
	.def("solveLinearWithCache", &Matrix<float>::solveLinearWithCache)
        .def("linearRegression", &Matrix<float>::linearRegression);
	

     py::class_<Matrix<int>>(m, "MatrixInt")
        .def(py::init<int,int>())
        .def(py::init<vector<vector<int>>>())
        .def("display", &Matrix<int>::display)
        .def("getElement", &Matrix<int>::getElement)
        .def("setElement", &Matrix<int>::setElement) 
        .def("getNumberOfRows", &Matrix<int>::getNumberOfRows)
        .def("getNumberOfColumns", &Matrix<int>::getNumberOfColumns)
        .def("add", &Matrix<int>::add)
        .def("subtract", &Matrix<int>::subtract)
        .def("multiply", &Matrix<int>::multiply)
        .def("__add__", &Matrix<int>::add)
        .def("__sub__", &Matrix<int>::subtract)       
        .def("__mul__", &Matrix<int>::multiply)
        .def("transpose", &Matrix<int>::inverse); 

    
    

}     
