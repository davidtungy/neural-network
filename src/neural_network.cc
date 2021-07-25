#include "neural_network.h"

#include <iostream>
#include <assert.h>

using namespace std;


NeuralNetwork::NeuralNetwork() {
}

void NeuralNetwork::add_layer(int size_previous_layer, int size, string activation) {
	if (this->layers.empty()) {
		this->layers.push_back(new Layer(size_previous_layer, size, activation));
	} else {
		assert(this->layers.back()->get_size() == size_previous_layer);
		this->layers.push_back(new Layer(size_previous_layer, size, activation));
	}
}

double* NeuralNetwork::forward(double* input) {
	double* layer_output = input;
	for(int i = 0; i < this->layers.size(); i++) {
		layer_output = this->layers[i]->forward(layer_output);
	}
	return layer_output;
}