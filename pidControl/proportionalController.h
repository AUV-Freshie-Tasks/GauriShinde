#include <iostream>


class proportionalController{
private:
double kp;

public:

proportionalController(double k);

double get_Kp();
void set_Kp(double k);

double computePaction (double error);
};