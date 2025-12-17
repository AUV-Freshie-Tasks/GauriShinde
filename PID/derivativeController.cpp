#include "derivativeController.h"
//#include "integralController.h"
using namespace std;
double derivativeController::timeBetweenReadings =0.5;

derivativeController::derivativeController(double k){
    kd = k;
}

double derivativeController::get_Kd(){
    return kd;
}

void derivativeController::set_Kd(double k){
    kd = k;
}

double derivativeController::computeDaction(double error){
    //integralController i = integralController(1);
    double e = (error - oldError)/timeBetweenReadings;
    oldError = error;
    return kd*e;
}