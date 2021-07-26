#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <time.h>
#include "neuron.h"
#include "layer.h"
#include "neural_network.h"

using namespace std;

int main(int argc, char* argv[]) {
	srand (time(NULL));
	vector<double> input = {1, 1, 2};

	NeuralNetwork n;
	n.add_layer(3, 2, "sigmoid");
	n.add_layer(2, 2, "sigmoid");
	vector<double> output = n.forward(input);

}