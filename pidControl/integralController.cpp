#include <iostream>
#include <list>
#include "integralController.h"

// list<double> integralController::errorCache;
// const size_t integralController::CACHESIZE = 10;
double integralController::timeBetweenReadings =0.5;

integralController::integralController(double k){
    ki = k;
}

void integralController::set_Ki(double k){
    ki = k;
}

double integralController::get_Ki(){
    return ki;
}

// void integralController::addErrortoCache(double error){
//     errorCache.push_front(error);
//     cout<<"error added to cache"<<endl;
//     if(errorCache.size()> CACHESIZE){
//         cout<<"oldest error deleted"<<endl;
//         errorCache.pop_back();
//     }
// }

// double integralController::getErrorFromCache(int i){
//     return *next(errorCache.begin(), i-1);
// }

void integralController::eraseIntegral(){
    integral = 0;
}

double integralController::computeIaction(double error){
 //   addErrortoCache(error);
 //   double sum = 0;
    // for(double x: errorCache){
    //     sum += x;
    // }
    //cout<<sum<<endl;
    integral += error*timeBetweenReadings;
    return ki*integral;
}