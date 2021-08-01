#include "activation.h"

#include <cmath>

class Tanh : public ActivationFunction {
public:
	double calculate (double x) {
		return 2 / (1 + exp(-2 * x)) - 1;
	}
	double partial (double x) {
		return 1 - pow(calculate(x), 2);
	}
};
