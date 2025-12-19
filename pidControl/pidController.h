#include <iostream>
#include "proportionalController.h"
#include "integralController.h"
#include "derivativeController.h"

class pidController{
    private:
    proportionalController p = proportionalController(1);
    integralController i = integralController(1);
    derivativeController d = derivativeController(1);
    public:
    pidController(double P, double I, double D);
    
    void set_Kp(double k);
    void set_Ki(double k);
    void set_Kd(double k);

    double get_Kp();
    double get_Ki();
    double get_Kd();

    void eraseIntegral();
    void resetOldError();

    double computePIDaction(double error);
    
};