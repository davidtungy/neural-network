#include "neuron.h"

#include <iostream>

using namespace std;


Neuron::Neuron(int size){
	for (int i = 0; i < size; i++) {
		weights.push_back(random_weight());
	}
}

double Neuron::random_weight() {
	return ((double) rand()) / RAND_MAX;
}

vector<double> Neuron::get_weights() {
	return weights;
}

double Neuron::weighted_sum(vector<double> input) {
	vector<double> current_weights = get_weights();
	double sum = 0.0;
	for (int i = 0; i < current_weights.size(); i++) {
		cout << input[i] << "*" << current_weights[i] << " + ";
		sum += input[i] * current_weights[i];
	}
	return sum;
}

void Neuron::print_weights() {
	for (int i = 0; i < weights.size(); i++) {
		cout << weights[i] << endl;
	}
}
