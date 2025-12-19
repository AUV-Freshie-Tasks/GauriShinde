#include <iostream>
#include <list>
// #include "proportionalController.h"
// #include "integralController.h"
// #include "derivativeController.h"
#include "pidController.h"
using namespace std;


int main(){
    cout<<"proportional control"<<endl;
    proportionalController a = proportionalController(2);
    double b = a.get_Kp();
    cout<<b<<endl;
    double c = a.computePaction(3);
    cout<<c<<endl;
    cout<<"integral control"<<endl;
    integralController d = integralController(2);
    double e = d.get_Ki();
    cout<<e<<endl;
    double f = d.computeIaction(1);
    double g = d.computeIaction(2);
    double h = d.computeIaction(3);
    cout<<f<<" "<<g<<" "<<h<<endl;
    cout<<"derivative control"<<endl;
    derivativeController i = derivativeController(2);
    double j = i.get_Kd();
    cout<<j<<endl;
    double k = i.computeDaction(3);
    double l = i.computeDaction(3);
    cout<<k<<endl;
    cout<<l<<endl;
    cout<<"*************Testing PID*********"<<endl;
    pidController m = pidController(4,2,3);
    m.set_Kp(1);
    cout<<"p: "<<m.get_Kp()<<endl;
    cout<<"i: "<<m.get_Ki()<<endl;
    cout<<"d: "<<m.get_Kd()<<endl;
    cout<<"Testing all"<<endl;
    proportionalController P = proportionalController(1);
    integralController I = integralController(2);
    derivativeController D = derivativeController(3);
    double error = 3;
    for( int i = 0; i <10; i++){
        double x = P.computePaction(error);
        double y = I.computeIaction(error);
        double z = D.computeDaction(error);
        double n = m.computePIDaction(error);
        cout<<"------------"<<i<<"------------"<<endl;
        cout<<"p: "<<x<<endl;
        cout<<"i: "<<y<<endl;
        cout<<"d: "<<z<<endl; 
        cout<<"total: "<<n<<endl;
    }


    return 0;
}