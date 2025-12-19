#include "proportionalController.h"

proportionalController::proportionalController(double k){
    kp = k;
}

double proportionalController::get_Kp(){
    return kp;
}

void proportionalController::set_Kp(double k){
    kp = k;
}

double proportionalController::computePaction(double error){
    return kp*error;
}