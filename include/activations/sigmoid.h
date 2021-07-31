#include "activation.h"


#include <iostream>
#include <string>
#include <cmath>


using namespace std;


class Sigmoid : public ActivationFunction {
public:
	double calculate (double x) {
		return 1 / (1 + exp(-x));
	}
	double partial (double x) {
		return calculate(x) * (1 - calculate(x));
	}
};
