#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "pidController.h"
namespace py = pybind11;
using namespace std;

PYBIND11_MODULE(pidBind, m){
    py::class_<proportionalController>(m, "proportionalController")
        .def(py::init<double>())
        .def("set_Kp", &proportionalController::set_Kp)
        .def("get_Kp", &proportionalController::get_Kp)
        .def("computePaction", &proportionalController::computePaction);

    py::class_<integralController>(m,"integralController")
        .def(py::init<double>())
        .def("set_Ki", &integralController::set_Ki)
        .def("get_Ki", &integralController::get_Ki)
        .def("eraseIntegral", &integralController::eraseIntegral)
        .def("computeIaction", &integralController::computeIaction);
    
    py::class_<derivativeController>(m, "derivativeController")
        .def(py::init<double>())
        .def("set_Kd", &derivativeController::set_Kd)
        .def("get_Kd", &derivativeController::get_Kd)
        .def("resetOldError", &derivativeController::resetOldError)
        .def("computeDaction", &derivativeController::computeDaction);  

    py::class_<pidController>(m, "pidController")
        .def(py::init<double, double, double>())
        .def("set_Kp", &pidController::set_Kp)
        .def("get_Kp", &pidController::get_Kp)
        .def("set_Ki", &pidController::set_Ki)
        .def("get_Ki", &pidController::get_Ki)      
        .def("set_Kd", &pidController::set_Kd)
        .def("get_Kd", &pidController::get_Kd)
        .def("computePIDaction", &pidController::computePIDaction);

}