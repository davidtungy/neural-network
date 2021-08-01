#include "loss.h"

#include <cmath>
#include <queue>

class MSE : public Loss {
public:
	double calculate_loss (std::vector<double> actual, std::vector<double> predicted) {
		double sum = 0.0;
		for (int i = 0; i < actual.size(); i++) {
			sum += pow(actual[i] - predicted[i], 2);
		}
		return sum;
	}

	std::queue<double> partial (std::vector<double> actual, std::vector<double> predicted) {
		std::queue<double> q;
		for (int i = 0; i < actual.size(); i++) {
			q.push(-(actual[i] - predicted[i]));
		}
		return q;
	}
};
