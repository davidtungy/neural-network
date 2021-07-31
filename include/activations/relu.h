#include "activation.h"


#include <iostream>
#include <string>
#include <cmath>


using namespace std;


class ReLU : public ActivationFunction {
public:
	double calculate (double x) {
		return max(0.0, x);
	}
	double partial (double x) {
		return (x < 0) ? 0 : 1;
	}
};
