#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <time.h>
#include "neuron.h"
#include "layer.h"
#include "neural_network.h"
#include "activations/sigmoid.h"
#include "activations/relu.h"
#include "activations/tanh.h"
#include "activations/lrelu.h"
#include "loss.h"
#include "losses/mse.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand (time(NULL));
	vector<vector<double>> X_train = {{1, 1, 0.35, 1.41}};
	vector<vector<double>> y_train = {{0.2346, 0.83915}};

	NeuralNetwork n;
	n.add_layer(4, 10, new Tanh());
	n.add_layer(10, 10, new Tanh());
	n.add_layer(10, 2, new LReLU());
	n.set_loss(new MSE());

	for (int epoch = 0; epoch < 10000; epoch++) {
		// iterate across all training examples
		for (int i = 0; i < X_train.size(); i++) {
			vector<double> output = n.forward(X_train[i]);
			n.backward(y_train[i]);
			cout << "LOSS " << i << " : " << n.loss->calculate_loss(y_train[i], output) << endl;
			/*
			for (int j = 0; j < output.size(); j++) {
				cout << output[j] << " ";
			}
			cout << endl;
			for (int j = 0; j < y_train[i].size(); j++) {
				cout << y_train[i][j] << " ";
			}
			cout << endl;
			*/
		}
	}

}