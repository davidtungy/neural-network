#include "layer.h"
#include <iostream>


Layer::Layer(int num_nodes, string activation): num_nodes_(num_nodes), activation_(activation) {
	// initialize node weights to a random value between 0.0 and 1.0
	// allocate one extra layer for bias term
	for (int i = 0; i < num_nodes_ + 1; i++) {
		values_.push_back((double) rand() / (RAND_MAX));
	}
}

Layer::Layer(int num_nodes, double values[], string activation): num_nodes_(num_nodes), activation_(activation) {
	for (int i = 0; i < num_nodes_; i++) {
		values_.push_back(values[i]);
	}
}

vector<double> Layer::get_values() {
	return values_;
}

string Layer::get_activation() {
	return activation_;
}