#include <iostream>
// #include "proportionalController.h"
// #include "integralController.h"
// #include "derivativeController.h"
#include "pidController.h"
using namespace std;

pidController::pidController(double P, double I, double D){
    p.set_Kp(P);
    i.set_Ki(I);
    d.set_Kd (D);
}

void pidController::set_Kp(double k){
    p.set_Kp(k);
}

void pidController::set_Ki(double k){
    i.set_Ki(k);
}

void pidController::set_Kd(double k){
    d.set_Kd(k);
}

double pidController::get_Kp(){
    return p.get_Kp();
}
double pidController::get_Ki(){
    return i.get_Ki();
}
double pidController::get_Kd(){
    return d.get_Kd();
}

void pidController::eraseIntegral(){
    i.eraseIntegral();
}

void pidController::resetOldError(){
    d.resetOldError();
}


double pidController::computePIDaction(double error){
    // double a = p.computePaction(error);
    // double b = i.computeIaction(error);
    // double c = d.computeDaction(error);
    // cout<<"P output: "<<a<<endl;
    // cout<<"I output: "<<b<<endl;
    // cout<<"D output: "<<c<<endl;
    // cout<<"outside function"<<endl;
    // return a + b + c;
    return p.computePaction(error) + i.computeIaction(error)+ d.computeDaction(error);
}