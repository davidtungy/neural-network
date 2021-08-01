#include "loss.h"


#include <iostream>
#include <string>
#include <cmath>
#include <queue>


using namespace std;


class MSE : public Loss {
public:
	double calculate_loss (vector<double> actual, vector<double> predicted) {
		double sum = 0.0;
		for (int i = 0; i < actual.size(); i++) {
			sum += pow(actual[i] - predicted[i], 2);
		}
		return sum;
	}

	queue<double> partial (vector<double> actual, vector<double> predicted) {
		queue<double> q;
		for (int i = 0; i < actual.size(); i++) {
			q.push(-(actual[i] - predicted[i]));
		}
		return q;
	}
};
