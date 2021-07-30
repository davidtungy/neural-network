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
	vector<double> input = {1, 1, 2, 3, 0.2};

	NeuralNetwork n;
	n.add_layer(5, 2, "sigmoid");
	n.add_layer(2, 2, "sigmoid");
	cout << "FORWARD" << endl;
	vector<double> output = n.forward(input);

	vector<double> answer = {0.01, 0.99};
	
	for (int i = 0; i < 40000; i++) {
		n.backward(answer, input);
		n.forward(input);
	}
}