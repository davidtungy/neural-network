#include "neuron.h"

#include <iostream>

Neuron::Neuron(int size){
	for (int i = 0; i < size; i++) {
		weights.push_back(random_weight());
	}
}

double Neuron::random_weight() {
	return ((double) rand()) / RAND_MAX;
}

std::vector<double> Neuron::get_weights() {
	return weights;
}

double Neuron::weighted_sum(std::vector<double> input) {
	std::vector<double> current_weights = get_weights();
	double sum = 0.0;
	for (int i = 0; i < current_weights.size(); i++) {
		sum += input[i] * current_weights[i];
	}
	return sum;
}
