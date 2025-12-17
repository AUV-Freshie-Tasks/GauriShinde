using namespace std;

class derivativeController{
    private:
    double kd;
    double oldError {0};
    static double timeBetweenReadings;
    public:

    derivativeController(double k);

    double get_Kd();
    void set_Kd(double k);

    double computeDaction(double error);

};