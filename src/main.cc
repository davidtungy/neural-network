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

using namespace std;

int main(int argc, char* argv[]) {
	srand (time(NULL));
	vector<double> input = {1, 1, 0.35, 1.41};

	NeuralNetwork n;
	n.add_layer(4, 10, new Tanh());
	n.add_layer(10, 10, new Tanh());
	n.add_layer(10, 10, new LReLU());
	vector<double> output = n.forward(input);

	vector<double> answer = {0.2346, 0.83915, 0.3751, 0.3723, 0.946, 0.726, 0.52489, 0.636, 0.2, 0.5};
	
	// Print predictions every 100 iterations
	// TO DO: 
	// (1) Print loss instead
	// (2) Create training loop with multiple inputs
	// (3) Refactor into neural_network
	for (int i = 0; i < 25; i++) {
		n.backward(answer);
		output = n.forward(input);
		n.print_result();
		/*
		if (i % 5 == 0) {
			n.print_result();
		}
		*/
	}
}