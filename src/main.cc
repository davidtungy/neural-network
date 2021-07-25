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
	double input[3] = {1, 1, 2};

	NeuralNetwork n;
	n.add_layer(3, 5, "sigmoid");
	n.add_layer(5, 3, "sigmoid");
	double* output = n.forward(input);

}