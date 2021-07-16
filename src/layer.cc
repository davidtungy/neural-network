#include "layer.h"
#include <iostream>


Layer::Layer(int num_nodes, string activation): num_nodes_(num_nodes), activation_(activation) {
	// initialize node weights to a random value between 0.0 and 1.0
	// allocate one extra layer for bias term
	for (int i = 0; i < num_nodes_ + 1; i++) {
		values_.push_back((double) rand() / (RAND_MAX));
	}
}

Layer::Layer(double values[], string activation): activation_(activation) {
	num_nodes_ = sizeof(values)/sizeof(values[0]);
	values_ = vector<double>(values, values + num_nodes_);
}

vector<double> Layer::get_values() {
	return values_;
}

string Layer::get_activation() {
	return activation_;
}