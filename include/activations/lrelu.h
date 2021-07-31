#include "activation.h"


#include <iostream>
#include <string>
#include <cmath>


using namespace std;


class LReLU : public ActivationFunction {
private:
	double alpha;
public:
	LReLU(double alpha=0.01) : alpha(alpha) {};

	double calculate (double x) {
		return max(alpha * x, x);
	}
	double partial (double x) {
		return (x < 0) ? alpha : 1;
	}
};
