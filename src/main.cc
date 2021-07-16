#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "neural_network.h"
#include "layer.h"

using namespace std;

int main(int argc, char* argv[]) {
	Layer l1(10, "sigmoid");

	vector<double> values = l1.get_values();
	for (double v: values) {
		cout << v << endl;
	}

	NeuralNetwork nn;
	cout << "Created a neural network?" << endl;
}