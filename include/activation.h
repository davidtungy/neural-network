#include <cstdlib>
#include <iostream>
#include <cmath>

static double sigmoid (double x) {
	return 1 / (1 + exp(-x));
}