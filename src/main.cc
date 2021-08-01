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
	vector<vector<double>> X_train = {{1, 1, 0.35, 1.41}, {7, 1, 0.35, 1.41}, {7, 136.0, 3.14, 16.13}};
	vector<vector<double>> y_train = {{0.2346, 0.83915}, {0.7, 0.815}, {0.2, 1.52}};

	NeuralNetwork n;
	n.add_layer(4, 2, new Sigmoid());
	n.add_layer(2, 2, new Sigmoid());
	n.add_layer(2, 2, new ReLU());
	n.set_loss(new MSE());

	n.train(X_train, y_train);

}