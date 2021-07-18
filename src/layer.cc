#include "layer.h"
#include <iostream>

#include "neuron.h"


Layer::Layer(int num_nodes, string activation): size_(num_nodes + 1), activation_(activation) {
	// initialize node weights to a random value between 0.0 and 1.0
	// allocate one extra layer for bias term
	for (int i = 0; i < size_; i++) {
		double random = ((double) rand()) / RAND_MAX;
		Neuron* n = new Neuron(random);
		weights_.push_back(n);
	}
}

Layer::Layer(int num_nodes, vector<double> weights, string activation): size_(num_nodes), activation_(activation) {
	for (int i = 0; i < size_; i++) {
		Neuron* n = new Neuron(weights[i]);
		weights_.push_back(n);
	}
}

vector<Neuron*> Layer::get_weights() {
	return weights_;
}

string Layer::get_activation() {
	return activation_;
}