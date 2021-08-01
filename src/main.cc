#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <random>
#include <vector>

#include "neural_network.h"
#include "activations/sigmoid.h"
#include "activations/relu.h"
#include "activations/tanh.h"
#include "activations/lrelu.h"
#include "loss.h"
#include "losses/mse.h"

int main(int argc, char* argv[]) {
	srand (time(NULL));

	// Define a nonlinear multivariable function:
	// (x1, x2, x3, x4) => (y1, y2), where:
	// y1 = x3 + (1.8 * x1) - x2 + x4
	// y2 = x1 + x4 * x2

	// Generate 500 training examples in the space:
	// x1: [0, 2]
	// x2: [-2, 0]
	// x3: [1, 2]
	// x4: [-2, -1]

	std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_real_distribution<double> x1_distr(0, 2);
    std::uniform_real_distribution<double> x2_distr(-2, 0);
    std::uniform_real_distribution<double> x3_distr(1, 2);
    std::uniform_real_distribution<double> x4_distr(-2, -1);

    std::vector<std::vector<double>> X_train;
	std::vector<std::vector<double>> y_train;

	std::vector<std::vector<double>> X_val;
	std::vector<std::vector<double>> y_val;

	for (int i = 0; i < 600; i++) {
		double x1 = x1_distr(eng);
		double x2 = x2_distr(eng);
		double x3 = x3_distr(eng);
		double x4 = x4_distr(eng);
		double y1 = x3 + (1.8 * x1) - x2 + x4;
		double y2 = x1 + x4 * x2;
		std::vector<double> X = {x1, x2, x3, x4};
		std::vector<double> y = {y1, y2};
		if (i < 500) {
			X_train.push_back(X);
			y_train.push_back(y);
		} else {
			X_val.push_back(X);
			y_val.push_back(y);
		}
	}

	NeuralNetwork n;
	n.add_layer(4, 2, new Sigmoid());
	n.add_layer(2, 2, new Sigmoid());
	n.add_layer(2, 2, new LReLU());
	n.set_loss(new MSE());

	n.train(X_train, y_train);
	n.validate(X_val, y_val);
}