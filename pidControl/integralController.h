#include <list>
using namespace std;

class integralController{
private:
double ki;
double integral;

static list<double> errorCache;
static const size_t CACHESIZE;
static double timeBetweenReadings;

public:

integralController(double k);

double get_Ki();
void set_Ki(double k);

// void addErrortoCache(double error);
// double getErrorFromCache(int i);

void eraseIntegral();

double computeIaction(double error);


};