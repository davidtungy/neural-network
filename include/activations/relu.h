#include "activation.h"

#include <cmath>

class ReLU : public ActivationFunction {
public:
	double calculate (double x) {
		return std::max(0.0, x);
	}
	double partial (double x) {
		return (x < 0) ? 0 : 1;
	}
};
